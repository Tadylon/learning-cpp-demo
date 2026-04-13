#include <iostream>

using namespace std;

// This function returns a letter grade based on the average of a student
char gradeFunction(double avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

int main() {
    int count; // Number of grades the user wants to enter
    double sum = 0, grade; // Sum stores total grades, grade holds each input

    // Ask the user to enter total grades between 1 to 5
    cout << "How many grades (1 to 5)? ";
    cin >> count;

    // Validate that count is between 1 and 5
    if (count < 1 || count > 5) {
        cout << "Invalid number. You must enter between 1 and 5 grades.\n";
        return 1;  // Exit
    }

    // Loop to collect each grade
    for (int i = 1; i <= count; i++) {
        cout << "Enter grade " << i << ": ";
        cin >> grade;
        sum += grade;
    }

    // Calculate the average score
    double avg = sum / count;

    // Display numeric average
    cout << "Average: " << avg << "\n";

    // Display letter grade
    cout << "Letter grade: " << gradeFunction(avg) << "\n";

    return 0;
}