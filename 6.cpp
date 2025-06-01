// Case Study 6: Flight Seat Reservation System (Standalone)
#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 4;

void displaySeats(char seats[ROWS][COLS]) {
    cout << "\nSeating Chart (E = Empty, B = Booked):\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

void bookSeat(char seats[ROWS][COLS]) {
    int row, col;
    cout << "\nEnter seat to book (Row 1-6, Col 1-4): ";
    cin >> row >> col;
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        cout << "Invalid seat position!\n";
    } else if (seats[row - 1][col - 1] == 'B') {
        cout << "Seat already booked!\n";
    } else {
        seats[row - 1][col - 1] = 'B';
        cout << "Seat successfully booked.\n";
    }
}

int countAvailableSeats(char seats[ROWS][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 'E') {
                count++;
            }
        }
    }
    return count;
}

int rowWithMaxEmptySeats(char seats[ROWS][COLS]) {
    int maxRow = 0, maxEmpty = 0;
    for (int i = 0; i < ROWS; i++) {
        int emptyCount = 0;
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 'E') {
                emptyCount++;
            }
        }
        if (emptyCount > maxEmpty) {
            maxEmpty = emptyCount;
            maxRow = i;
        }
    }
    return maxRow;
}

int main() {
    char seats[ROWS][COLS];
    // Initialize all seats as empty
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = 'E';
        }
    }

    int choice;
    do {
        cout << "\nFlight Seat Reservation System Menu:\n";
        cout << "1. Display Seating Chart\n";
        cout << "2. Book a Seat\n";
        cout << "3. Count Available Seats\n";
        cout << "4. Find Row with Max Empty Seats\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookSeat(seats);
                break;
            case 3:
                cout << "Available Seats: " << countAvailableSeats(seats) << endl;
                break;
            case 4:
                cout << "Row with max empty seats: Row " << rowWithMaxEmptySeats(seats) + 1 << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
