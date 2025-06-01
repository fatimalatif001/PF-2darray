#include <iostream>
using namespace std;

const int CANDIDATES = 4;
const int STATIONS = 6;

void inputVotes(int votes[STATIONS][CANDIDATES]) {
    cout << "Enter votes for each candidate at each polling station:\n";
    for (int i = 0; i < STATIONS; i++) {
        cout << "Polling Station " << i + 1 << ":\n";
        for (int j = 0; j < CANDIDATES; j++) {
            cout << "  Candidate " << j + 1 << ": ";
            cin >> votes[i][j];
            while (votes[i][j] < 0) {
                cout << "Invalid votes! Enter non-negative number: ";
                cin >> votes[i][j];
            }
        }
    }
}

void totalVotesPerCandidate(int votes[STATIONS][CANDIDATES], int totalVotes[CANDIDATES]) {
    for (int j = 0; j < CANDIDATES; j++) {
        totalVotes[j] = 0;
        for (int i = 0; i < STATIONS; i++) {
            totalVotes[j] += votes[i][j];
        }
    }
}

void totalVotesPerStation(int votes[STATIONS][CANDIDATES], int totalPerStation[STATIONS]) {
    for (int i = 0; i < STATIONS; i++) {
        totalPerStation[i] = 0;
        for (int j = 0; j < CANDIDATES; j++) {
            totalPerStation[i] += votes[i][j];
        }
    }
}

void findWinners(int totalVotes[CANDIDATES]) {
    int maxVotes = totalVotes[0];
    for (int i = 1; i < CANDIDATES; i++) {
        if (totalVotes[i] > maxVotes) {
            maxVotes = totalVotes[i];
        }
    }
    cout << "\nWinner(s): ";
    for (int i = 0; i < CANDIDATES; i++) {
        if (totalVotes[i] == maxVotes) {
            cout << "Candidate " << i + 1 << " ";
        }
    }
    cout << "with " << maxVotes << " votes.\n";
}

void checkLowTurnout(int totalPerStation[STATIONS]) {
    cout << "\nPolling stations with turnout less than 100:\n";
    bool found = false;
    for (int i = 0; i < STATIONS; i++) {
        if (totalPerStation[i] < 100) {
            cout << "Station " << i + 1 << " with turnout " << totalPerStation[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "All stations have turnout >= 100.\n";
    }
}

int main() {
    int votes[STATIONS][CANDIDATES];
    int totalVotes[CANDIDATES];
    int totalPerStation[STATIONS];

    inputVotes(votes);
    totalVotesPerCandidate(votes, totalVotes);
    totalVotesPerStation(votes, totalPerStation);

    cout << "\nTotal votes per candidate:\n";
    for (int i = 0; i < CANDIDATES; i++) {
        cout << "Candidate " << i + 1 << ": " << totalVotes[i] << endl;
    }

    cout << "\nTotal votes per polling station:\n";
    for (int i = 0; i < STATIONS; i++) {
        cout << "Station " << i + 1 << ": " << totalPerStation[i] << endl;
    }

    findWinners(totalVotes);
    checkLowTurnout(totalPerStation);

    return 0;
}
