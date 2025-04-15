#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to convert grade letter to grade point
double gradeToPoint(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    if (grade == "A-" || grade == "a-") return 3.7;
    if (grade == "B+" || grade == "b+") return 3.3;
    if (grade == "B" || grade == "b") return 3.0;
    if (grade == "B-" || grade == "b-") return 2.7;
    if (grade == "C+" || grade == "c+") return 2.3;
    if (grade == "C" || grade == "c") return 2.0;
    if (grade == "C-" || grade == "c-") return 1.7;
    if (grade == "D+" || grade == "d+") return 1.3;
    if (grade == "D" || grade == "d") return 1.0;
    if (grade == "F" || grade == "f") return 0.0;
    return -1.0; // Invalid grade
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<int> courseCredits(numCourses);
    vector<string> courseGrades(numCourses);
    vector<double> gradePoints(numCourses);

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for Course " << i + 1 << ":" << endl;
        cout << "Course Name: ";
        cin.ignore(); // Consume newline left in the buffer.
        getline(cin, courseNames[i]);

        cout << "Credits: ";
        cin >> courseCredits[i];

        cout << "Grade (e.g., A, B+, C-): ";
        cin >> courseGrades[i];

        gradePoints[i] = gradeToPoint(courseGrades[i]);

        if (gradePoints[i] == -1.0) {
            cout << "Invalid grade entered. Please re-enter the data for this course." << endl;
            --i; // Re-enter the current course data
            continue;
        }

        totalCredits += courseCredits[i];
        totalGradePoints += gradePoints[i] * courseCredits[i];
    }

    // Display course details
    cout << "\nCourse Details:" << endl;
    cout << left << setw(20) << "Course Name" << setw(10) << "Credits" << setw(10) << "Grade" << setw(15) << "Grade Points" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < numCourses; ++i) {
        cout << left << setw(20) << courseNames[i] << setw(10) << courseCredits[i] << setw(10) << courseGrades[i] << setw(15) << fixed << setprecision(2) << gradePoints[i] << endl;
    }

    // Calculate and display GPA and CGPA
    if (totalCredits > 0) {
        double gpa = totalGradePoints / totalCredits;
        cout << "\nTotal Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << fixed << setprecision(2) << totalGradePoints << endl;
        cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
        cout << "CGPA: " << fixed << setprecision(2) << gpa << endl; // In this single semester case GPA and CGPA are the same.
    } else {
        cout << "\nNo valid course data entered." << endl;
    }

    return 0;
}