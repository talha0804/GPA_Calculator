#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string CourseName;
    double Credits;
    string Grades; // Change from char to string
};

static const int Max_subjects = 10;
Course courses[Max_subjects];
int SubjectCount;

void SetData()
{
    cout << "Enter Your Subject Name, Grades, and Credits:" << endl;
    for (int i = 0; i < SubjectCount; i++)
    {
        cout << "Subject " << i + 1 << " Name: ";
        cin >> courses[i].CourseName;
        cout << "Subject " << i + 1 << " Grades: ";
        cin >> courses[i].Grades;
        cout << "Subject " << i + 1 << " Credits: ";
        cin >> courses[i].Credits;
    }
}

double TotalCredits()
{
    int totalcredits = 0;
    for (int i = 0; i < SubjectCount; i++)
    {
        totalcredits += courses[i].Credits;
    }
    return totalcredits;
}

double GradePoints()
{
    double TotalGradesPoints = 0.0;
    for (int i = 0; i < SubjectCount; i++)
    {
        double points;
        if (courses[i].Grades == "A")
            points = 4.0;
        else if (courses[i].Grades == "A-")
            points = 3.7;
        else if (courses[i].Grades == "B+")
            points = 3.3;
        else if (courses[i].Grades == "B")
            points = 3.0;
        else if (courses[i].Grades == "B-")
            points = 2.7;
        else if (courses[i].Grades == "C+")
            points = 2.3;
        else if (courses[i].Grades == "C")
            points = 2.0;
        else if (courses[i].Grades == "C-")
            points = 1.7;
        else if (courses[i].Grades == "D+")
            points = 1.3;
        else if (courses[i].Grades == "D")
            points = 1.0;
        else if (courses[i].Grades == "F")
            points = 0.0;
        else
            points = 0.0; // Handle invalid grades gracefully

        TotalGradesPoints += points * courses[i].Credits;
    }
    return TotalGradesPoints;
}

double calculateGPa()
{
    return GradePoints() / TotalCredits();
}

int main()
{
    cout << "Enter Your Total Subject Count: ";
    cin >> SubjectCount;

    if (SubjectCount > Max_subjects)
    {
        cout << "Subject count exceeds the maximum allowed subjects of " << Max_subjects << endl;
        return 1;
    }

    SetData();
    double gpa = calculateGPa();
    cout << "Your GPA is: " << gpa << endl;

    return 0;
}
