#include <iostream>
using namespace std;

const int STUDENTS = 10;
const int SUBJECTS = 5;

void inputMarks(int marks[STUDENTS][SUBJECTS]) {
    cout << "Enter marks of 10 students in 5 subjects:\n";
    for (int i = 0; i < STUDENTS; i++) {
        for (int j = 0; j < SUBJECTS; j++) {
            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }
}

void calculateTotals(int marks[STUDENTS][SUBJECTS], int total[], float avg[]) {
    for (int i = 0; i < STUDENTS; i++) {
        total[i] = 0;
        for (int j = 0; j < SUBJECTS; j++) {
            total[i] += marks[i][j];
        }
        avg[i] = total[i] / (float)SUBJECTS;
    }
}

int findTopScorer(int total[]) {
    int maxIndex = 0;
    for (int i = 1; i < STUDENTS; i++) {
        if (total[i] > total[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

char calculateGrade(float avg) {
    if (avg >= 80) return 'A';
    if (avg >= 60) return 'B';
    if (avg >= 40) return 'C';
    return 'F';
}

void displayResults(int total[], float avg[]) {
    cout << "\nResults:\n";
    for (int i = 0; i < STUDENTS; i++) {
        cout << "Student " << i + 1 << ": Total = " << total[i] << ", Avg = " << avg[i] << ", Grade = " << calculateGrade(avg[i]) << endl;
    }
    int topScorer = findTopScorer(total);
    cout << "\nTop Scorer: Student " << topScorer + 1 << " with " << total[topScorer] << " marks.\n";
}

int main() {
    int marks[STUDENTS][SUBJECTS];
    int total[STUDENTS];
    float avg[STUDENTS];

    inputMarks(marks);
    calculateTotals(marks, total, avg);
    displayResults(total, avg);

    return 0;
}