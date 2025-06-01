#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

void inputTemperatures(float temp[ROWS][COLS]) {
    cout << "\nEnter temperatures for 5x5 grid (each cell):\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "Location [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> temp[i][j];
        }
    }
}

void averageRowTemperatures(float temp[ROWS][COLS], float avg[ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        float sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / COLS;
    }
}

void findExtremeSpots(float temp[ROWS][COLS], float &maxTemp, float &minTemp) {
    maxTemp = temp[0][0];
    minTemp = temp[0][0];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (temp[i][j] > maxTemp)
                maxTemp = temp[i][j];
            if (temp[i][j] < minTemp)
                minTemp = temp[i][j];
        }
    }
}

void displayTemperatureReport(float temp[ROWS][COLS], float avg[ROWS], float maxTemp, float minTemp) {
    cout << "\nAverage Temperature of Each Row (Zone):\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Zone " << i + 1 << ": " << avg[i] << " degrees\n";
    }

    cout << "\nExtreme Hot Spot Temperature: " << maxTemp << " degrees\n";
    cout << "Extreme Cold Spot Temperature: " << minTemp << " degrees\n";
}

int main() {
    float temp[ROWS][COLS];
    float avg[ROWS];
    float maxTemp, minTemp;

    inputTemperatures(temp);
    averageRowTemperatures(temp, avg);
    findExtremeSpots(temp, maxTemp, minTemp);
    displayTemperatureReport(temp, avg, maxTemp, minTemp);

    return 0;
}