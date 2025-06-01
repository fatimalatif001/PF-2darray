source.cpp
#include <iostream>
using namespace std;

const int TEAMS = 6;
const int ROUNDS = 4;

void inputScores(int scores[TEAMS][ROUNDS]) {
    cout << "Enter scores for 6 teams in 4 rounds:\n";
    for (int i = 0; i < TEAMS; i++) {
        cout << "Team " << i + 1 << ":\n";
        for (int j = 0; j < ROUNDS; j++) {
            cout << "  Round " << j + 1 << ": ";
            cin >> scores[i][j];
            while (scores[i][j] < 0) {
                cout << "Invalid score! Enter again: ";
                cin >> scores[i][j];
            }
        }
    }
}

void totalScores(int scores[TEAMS][ROUNDS], int total[TEAMS]) {
    for (int i = 0; i < TEAMS; i++) {
        total[i] = 0;
        for (int j = 0; j < ROUNDS; j++) {
            total[i] += scores[i][j];
        }
    }
}

void findWinnerRunnerUp(int total[TEAMS], int &winner, int &runnerUp) {
    int max1 = -1, max2 = -1;
    winner = -1;
    runnerUp = -1;
    for (int i = 0; i < TEAMS; i++) {
        if (total[i] > max1) {
            max2 = max1;
            runnerUp = winner;
            max1 = total[i];
            winner = i;
        } else if (total[i] > max2 && total[i] != max1) {
            max2 = total[i];
            runnerUp = i;
        }
    }
}

void displayLowScoringTeams(int scores[TEAMS][ROUNDS]) {
    cout << "\nTeams that scored <= 10 in any round:\n";
    bool found = false;
    for (int i = 0; i < TEAMS; i++) {
        for (int j = 0; j < ROUNDS; j++) {
            if (scores[i][j] <= 10) {
                cout << "Team " << i + 1 << " scored " << scores[i][j] << " in Round " << j + 1 << endl;
                found = true;
                break; // Just show once per team
            }
        }
    }
    if (!found) {
        cout << "No team scored 10 or less in any round.\n";
    }
}

int main() {
    int scores[TEAMS][ROUNDS];
    int total[TEAMS];
    int winner, runnerUp;

    inputScores(scores);
    totalScores(scores, total);

    cout << "\nTotal scores per team:\n";
    for (int i = 0; i < TEAMS; i++) {
        cout << "Team " << i + 1 << ": " << total[i] << endl;
    }

    findWinnerRunnerUp(total, winner, runnerUp);

    cout << "\nWinner: Team " << winner + 1 << " with " << total[winner] << " points.\n";
    if (runnerUp != -1)
        cout << "Runner-up: Team " << runnerUp + 1 << " with " << total[runnerUp] << " points.\n";

    displayLowScoringTeams(scores);

    return 0;
}