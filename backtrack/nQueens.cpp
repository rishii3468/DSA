#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Global variables
vector<vector<char>> grid;
vector<vector<string>> result;

// Function to check if a queen can be placed at grid[row][col]
bool canPlaceQueen(int row, int col, int n) {
    // Check vertical column
    for (int i = row - 1; i >= 0; i--) {
        if (grid[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    int p = row - 1, q = col - 1;
    while (p >= 0 && q >= 0) {
        if (grid[p][q] == 'Q') return false;
        p--;
        q--;
    }

    // Check upper-right diagonal
    p = row - 1;
    q = col + 1;
    while (p >= 0 && q < n) {
        if (grid[p][q] == 'Q') return false;
        p--;
        q++;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
void solve(int row, int n) {
    if (row == n) {
        vector<string> solution;
        for (int i = 0; i < n; i++) {
            string rowStr(grid[i].begin(), grid[i].end());
            solution.push_back(rowStr);
        }
        result.push_back(solution);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (canPlaceQueen(row, i, n)) {
            grid[row][i] = 'Q';
            solve(row + 1, n);
            grid[row][i] = '.';
        }
    }
}

// Main function to initialize and solve
vector<vector<string>> solveNQueens(int n) {
    grid.assign(n, vector<char>(n, '.'));
    result.clear();
    solve(0, n);
    return result;
}

// Driver code
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << endl;
    for (const auto& sol : solutions) {
        for (const string& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
