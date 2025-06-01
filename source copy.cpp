source.cpp
#include <iostream>
using namespace std;

const int ITEMS = 4;
const int DAYS = 7;

void inputSales(float sales[ITEMS][DAYS]) {
    cout << "\nEnter daily sales for 4 items over 7 days:\n";
    for (int i = 0; i < ITEMS; i++) {
        for (int j = 0; j < DAYS; j++) {
            cout << "Item " << i + 1 << ", Day " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}

void calculateTotals(float sales[ITEMS][DAYS], float itemTotals[], float dayTotals[]) {
    for (int i = 0; i < ITEMS; i++) {
        itemTotals[i] = 0;
        for (int j = 0; j < DAYS; j++) {
            itemTotals[i] += sales[i][j];
        }
    }
    for (int j = 0; j < DAYS; j++) {
        dayTotals[j] = 0;
        for (int i = 0; i < ITEMS; i++) {
            dayTotals[j] += sales[i][j];
        }
    }
}

int findMaxDay(float dayTotals[]) {
    int maxIndex = 0;
    for (int i = 1; i < DAYS; i++) {
        if (dayTotals[i] > dayTotals[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int findTopItem(float itemTotals[]) {
    int maxIndex = 0;
    for (int i = 1; i < ITEMS; i++) {
        if (itemTotals[i] > itemTotals[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void displaySalesReport(float itemTotals[], float dayTotals[]) {
    cout << "\nTotal Sales per Item:\n";
    for (int i = 0; i < ITEMS; i++) {
        cout << "Item " << i + 1 << ": Rs. " << itemTotals[i] << endl;
    }
    cout << "\nTotal Sales per Day:\n";
    for (int j = 0; j < DAYS; j++) {
        cout << "Day " << j + 1 << ": Rs. " << dayTotals[j] << endl;
    }
    cout << "\nDay with Highest Sales: Day " << findMaxDay(dayTotals) + 1 << endl;
    cout << "Top Selling Item: Item " << findTopItem(itemTotals) + 1 << endl;
}

int main() {
    float sales[ITEMS][DAYS];
    float itemTotals[ITEMS];
    float dayTotals[DAYS];

    inputSales(sales);
    calculateTotals(sales, itemTotals, dayTotals);
    displaySalesReport(itemTotals, dayTotals);

    return 0;
}