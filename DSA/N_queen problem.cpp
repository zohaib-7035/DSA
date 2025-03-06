#include <iostream>
using namespace std;

bool is_safe(int **arr, int x, int y, int n) {
    for (int row = 0; row < x; row++) {
        if (arr[row][y] == 1) {
            return false;
        }
    }
    
    int i = x, j = y;
    while (i >= 0 && j >= 0) {
        if (arr[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }
    
    i = x;
    j = y;
    while (i >= 0 && j < n) {
        if (arr[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }
    
    return true;
}

bool n_queens(int **arr, int x, int n) {
    if (x >= n) {
        return true;
    }
    
    for (int i = 0; i < n; i++) {
        if (is_safe(arr, x, i, n)) {
            arr[x][i] = 1;
            
            if (n_queens(arr, x + 1, n)) {
                return true;
            }
            
            arr[x][i] = 0;
        }
    }
    
    return false;
}

void print_solution(int **arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    if (n_queens(arr, 0, n)) {
        print_solution(arr, n);
    } else {
        cout << "No solution exists." << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
