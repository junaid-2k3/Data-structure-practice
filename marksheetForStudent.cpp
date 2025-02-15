#include <iostream>
using namespace std;

int main() {
    // Define a 4D array for grades
    float grades[3][5][4][2] = {{{{0}}}}; // Initialized to 0

    // Input grades for all students
    for (int classID = 0; classID < 3; classID++) {
        cout << "Class " << (classID + 10) << ":\n";
        for (int student = 0; student < 5; student++) {
            cout << "  Student " << student + 1 << ":\n";
            for (int subject = 0; subject < 4; subject++) {
                for (int term = 0; term < 2; term++) {
                    cout << "    Enter grade for Subject " << subject + 1
                         << " (Term " << (term == 0 ? "Midterm" : "Final") << "): ";
                    cin >> grades[classID][student][subject][term];
                }
            }
        }
    }

    // Example: Retrieve and display grades for Class 10, Student 2, Math, Final term
    cout << "\nClass 10, Student 2, Math, Final term grade: "
         << grades[0][1][0][1] << "\n";

    // Example: Calculate average grade for a specific student
    int targetClass = 1; // Class 11
    int targetStudent = 3; // Student 4
    float total = 0;
    int count = 0;

    for (int subject = 0; subject < 4; subject++) {
        for (int term = 0; term < 2; term++) {
            total += grades[targetClass][targetStudent][subject][term];
            count++;
        }
    }

    cout << "Average grade for Class 11, Student 4: " << (total / count) << "\n";

    return 0;
}
