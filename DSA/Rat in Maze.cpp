#include <iostream>
using namespace std;

bool is_safe(int** arr, int x, int y, int n) {
    // Check if (x, y) is a valid cell to move to
    if (x < n && y < n && arr[x][y] == 1) {
        return true;
    }
    return false;
}

bool solve_maze(int** arr, int x, int y, int n, int** sol) {
    // Base case: if (x, y) is the destination
    if (x == n - 1 && y == n - 1 && arr[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if arr[x][y] is a valid move
    if (is_safe(arr, x, y, n)) {
        sol[x][y] = 1; // Mark this cell as part of the solution path

        // Move right in the maze
        if (solve_maze(arr, x + 1, y, n, sol)) {
            return true;
        }

        // Move down in the maze
        if (solve_maze(arr, x, y + 1, n, sol)) {
            return true;
        }

        sol[x][y] = 0; // Backtrack if moving right and down both failed
        return false;
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    // Dynamically allocate memory for the maze
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    cout << "Enter the maze (1 for path, 0 for block):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Dynamically allocate memory for the solution matrix
    int** sol = new int*[n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n]();
    }

    if (solve_maze(arr, 0, 0, n, sol)) {
        cout << "Solution path:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found!" << endl;
    }

    // Deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] sol[i];
    }
    delete[] arr;
    delete[] sol;

    return 0;
}
