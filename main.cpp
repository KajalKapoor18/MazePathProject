#include <iostream>
#include <vector>
#define R 3
#define C 3
using namespace std;

const int N = 5;

void printSolution(const vector<vector<int>>& sol) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int endX, int endY, vector<vector<int>>& sol) {
    if (x == endX && y == endY) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        sol[x][y] = 1;

        if (solveMazeUtil(maze, x, y + 1, endX, endY, sol))
            return true;

        if (solveMazeUtil(maze, x + 1, y, endX, endY, sol))
            return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int maze[N][N]) {
    vector<vector<int>> sol(N, vector<int>(N, 0));

    int startX, startY, endX, endY;
    cout << "Enter the starting position (row col): ";
    cin >> startX >> startY;
    cout << "Enter the endpoint position (row col): ";
    cin >> endX >> endY;

    if (!solveMazeUtil(maze, startX, startY, endX, endY, sol))
        cout << "No solution exists";
    else
        printSolution(sol);
}

// Function to count paths with exactly 'k' coins
int pathCount(int mat[][C], int m, int n, int k) {
    // Base cases
    if (m < 0 || n < 0 || k < 0) return 0;
    if (m == 0 && n == 0) return (k == mat[m][n]);

    // (m, n) can be reached either through (m-1, n) or
    // through (m, n-1)
    return pathCount(mat, m - 1, n, k - mat[m][n]) +
        pathCount(mat, m, n - 1, k - mat[m][n]);
}

// A wrapper over pathCountRec()
int pathCount(int mat[][C], int k) {
    return pathCount(mat, R - 1, C - 1, k);
}

int main() {
    int choice;
    cout << "Enter 1 for the maze solving program or 2 for the path counting program: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int maze[N][N] = { {1, 0, 1, 0, 0},
                               {1, 1, 0, 1, 0},
                               {0, 1, 1, 1, 0},
                               {0, 0, 0, 1, 0},
                               {0, 0, 0, 1, 1} };
            solveMaze(maze);
            break;
        }
        case 2: {
            // A Naive Recursive C++ program
            // to count paths with exactly
            // 'k' coins
            cout<<"Enter the sum you want!"<<endl;
            int sum;
            cin>>sum;
            int mat[R][C] = { {1, 2, 3},
                            {5, 6, 5},
                            {3, 2, 1}
                        };
            cout << pathCount(mat, sum);
            cout<<" : are the number of possible ways to get the sum";
            break;
        }
        default:
            cout << "Invalid choice!";
    }

    return 0;
}