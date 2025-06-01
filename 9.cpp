#include <iostream>
using namespace std;

const int SHIFTS = 3;
const int DAYS = 7;

void inputDefects(float defects[SHIFTS][DAYS]) {
    cout << "Enter defect percentages for each shift and day:\n";
    for (int i = 0; i < SHIFTS; i++) {
        for (int j = 0; j < DAYS; j++) {
            cout << "Shift " << i + 1 << ", Day " << j + 1 << ": ";
            cin >> defects[i][j];
            while (defects[i][j] < 0 || defects[i][j] > 100) {
                cout << "Invalid percentage! Enter between 0 and 100: ";
                cin >> defects[i][j];
            }
        }
    }
}

void avgDefectsPerShift(float defects[SHIFTS][DAYS], float avgShift[SHIFTS]) {
    for (int i = 0; i < SHIFTS; i++) {
        float sum = 0;
        for (int j = 0; j < DAYS; j++) {
            sum += defects[i][j];
        }
        avgShift[i] = sum / DAYS;
    }
}

void avgDefectsPerDay(float defects[SHIFTS][DAYS], float avgDay[DAYS]) {
    for (int j = 0; j < DAYS; j++) {
        float sum = 0;
        for (int i = 0; i < SHIFTS; i++) {
            sum += defects[i][j];
        }
        avgDay[j] = sum / SHIFTS;
    }
}

void identifyCriticalShifts(float avgShift[SHIFTS]) {
    cout << "\nCritical Shifts (avg defect > 10%):\n";
    bool found = false;
    for (int i = 0; i < SHIFTS; i++) {
        if (avgShift[i] > 10) {
            cout << "Shift " << i + 1 << " with average defect: " << avgShift[i] << "%\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No critical shifts found.\n";
    }
}

int main() {
    float defects[SHIFTS][DAYS];
    float avgShift[SHIFTS];
    float avgDay[DAYS];

    inputDefects(defects);
    avgDefectsPerShift(defects, avgShift);
    avgDefectsPerDay(defects, avgDay);

    cout << "\nAverage Defects Per Shift:\n";
    for (int i = 0; i < SHIFTS; i++) {
        cout << "Shift " << i + 1 << ": " << avgShift[i] << "%\n";
    }

    cout << "\nAverage Defects Per Day:\n";
    for (int j = 0; j < DAYS; j++) {
        cout << "Day " << j + 1 << ": " << avgDay[j] << "%\n";
    }

    identifyCriticalShifts(avgShift);

    return 0;
}
