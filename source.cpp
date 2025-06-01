#include <iostream>
using namespace std;

const int PATIENTS = 5;
const int DAYS = 7;

void inputStatus(char status[PATIENTS][DAYS]) {
    cout << "\nEnter patient status (S = Stable, C = Critical, R = Recovered):\n";
    for (int i = 0; i < PATIENTS; i++) {
        for (int j = 0; j < DAYS; j++) {
            cout << "Patient " << i + 1 << ", Day " << j + 1 << ": ";
            cin >> status[i][j];
        }
    }
}

void countStatus(char status[PATIENTS][DAYS], int &stable, int &critical, int &recovered) {
    stable = critical = recovered = 0;
    for (int i = 0; i < PATIENTS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (status[i][j] == 'S' || status[i][j] == 's') stable++;
            else if (status[i][j] == 'C' || status[i][j] == 'c') critical++;
            else if (status[i][j] == 'R' || status[i][j] == 'r') recovered++;
        }
    }
}

void countCriticalDays(char status[PATIENTS][DAYS], int criticalDays[PATIENTS]) {
    for (int i = 0; i < PATIENTS; i++) {
        criticalDays[i] = 0;
        for (int j = 0; j < DAYS; j++) {
            if (status[i][j] == 'C' || status[i][j] == 'c') {
                criticalDays[i]++;
            }
        }
    }
}

void displayReport(int stable, int critical, int recovered, int criticalDays[PATIENTS]) {
    cout << "\nTotal Stable Records: " << stable;
    cout << "\nTotal Critical Records: " << critical;
    cout << "\nTotal Recovered Records: " << recovered << endl;

    cout << "\nCritical Days per Patient:\n";
    for (int i = 0; i < PATIENTS; i++) {
        cout << "Patient " << i + 1 << ": " << criticalDays[i] << " day(s) critical\n";
    }
}

int main() {
    char status[PATIENTS][DAYS];
    int stable, critical, recovered;
    int criticalDays[PATIENTS];

    inputStatus(status);
    countStatus(status, stable, critical, recovered);
    countCriticalDays(status, criticalDays);
    displayReport(stable, critical, recovered, criticalDays);

    return 0;
}