// Case Study 7: Product Rating Dashboard (Standalone)
#include <iostream>
using namespace std;

const int USERS = 10;
const int PRODUCTS = 5;

void inputRatings(int ratings[USERS][PRODUCTS]) {
    cout << "\nEnter ratings (1 to 5) for " << PRODUCTS << " products by " << USERS << " users:\n";
    for (int i = 0; i < USERS; i++) {
        cout << "User " << i + 1 << ": ";
        for (int j = 0; j < PRODUCTS; j++) {
            cin >> ratings[i][j];
            while (ratings[i][j] < 1 || ratings[i][j] > 5) {
                cout << "Invalid! Enter again (1-5): ";
                cin >> ratings[i][j];
            }
        }
    }
}

void averageRatings(int ratings[USERS][PRODUCTS], float avg[PRODUCTS]) {
    for (int j = 0; j < PRODUCTS; j++) {
        int sum = 0;
        for (int i = 0; i < USERS; i++) {
            sum += ratings[i][j];
        }
        avg[j] = (float)sum / USERS;
    }
}

void perfectRatingCount(int ratings[USERS][PRODUCTS], int count[PRODUCTS]) {
    for (int j = 0; j < PRODUCTS; j++) {
        count[j] = 0;
        for (int i = 0; i < USERS; i++) {
            if (ratings[i][j] == 5) {
                count[j]++;
            }
        }
    }
}

void worstRatedProducts(float avg[PRODUCTS]) {
    float minAvg = avg[0];
    for (int j = 1; j < PRODUCTS; j++) {
        if (avg[j] < minAvg) {
            minAvg = avg[j];
        }
    }
    cout << "\nProduct(s) with worst average rating (" << minAvg << "): ";
    for (int j = 0; j < PRODUCTS; j++) {
        if (avg[j] == minAvg) {
            cout << "Product " << j + 1 << "  ";
        }
    }
    cout << endl;
}

int main() {
    int ratings[USERS][PRODUCTS];
    float avg[PRODUCTS];
    int perfectCount[PRODUCTS];

    inputRatings(ratings);
    averageRatings(ratings, avg);
    perfectRatingCount(ratings, perfectCount);

    cout << "\nAverage Ratings per Product:\n";
    for (int i = 0; i < PRODUCTS; i++) {
        cout << "Product " << i + 1 << ": " << avg[i] << endl;
    }

    cout << "\nNumber of Users who gave 5-star Rating:\n";
    for (int i = 0; i < PRODUCTS; i++) {
        cout << "Product " << i + 1 << ": " << perfectCount[i] << endl;
    }

    worstRatedProducts(avg);

    return 0;
}
