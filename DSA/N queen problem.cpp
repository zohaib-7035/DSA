#include <iostream>
using namespace std;

bool issafe(int arr[][4], int x, int y, int n) {
    // Check row on the left side
    for (int j = 0; j < y; ++j) {
        if (arr[x][j] == 1) {
            return false;
        }
    }

    // Check column on the upper side
    for (int i = 0; i < x; ++i) {
        if (arr[i][y] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    int a = x, b = y;
    while (a >= 0 && b >= 0) {
        if (arr[a][b] == 1) {
            return false;
        }
        a--;
        b--;
    }

    // Check upper right diagonal
    int i1 = x, j1 = y;
    while (i1 >= 0 && j1 < n) { // changed from j1 <= n to j1 < n
        if (arr[i1][j1] == 1) {
            return false;
        }
        i1--;
        j1++;
    }

    return true; // added missing return statement
}

bool N_queen(int arr[][4], int x, int n) {
    if (x >= n) {
        return true;
    }

    for (int i = 0; i < n; ++i) {
        if (issafe(arr, x, i, n)) {
            arr[x][i] = 1; // Place the queen

            if (N_queen(arr, x + 1, n)) {
                return true;
            }

            arr[x][i] = 0; // Backtrack
        }
    }

    return false; // No valid position found, need to backtrack
}

void printSolution(int arr[][4], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (up to 4): ";
    cin >> n;

    int arr[4][4] = {0}; // Initialize board with all zeros

    if (N_queen(arr, 0, n)) {
        printSolution(arr, n);
    } else {
        cout << "No solution exists for N = " << n << endl;
    }

    return 0;
}
