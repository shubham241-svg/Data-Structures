#include <iostream>
#include <vector>

using namespace std;

// NQUEENS

// Function to print the board
void printBoard(const vector<vector<char>> &board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at (row, col)
bool isSafe(const vector<vector<char>> &board, int row, int col) {
    int n = board.size();

    // Check vertical column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
void nQueens(vector<vector<char>> &board, int row) {
    int n = board.size();
    if (row == n) {
        printBoard(board); // Print the solution when all rows are filled
        return;
    }

    for (int j = 0; j < n; j++) { // Try placing a queen in each column
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';   // Place the queen
            nQueens(board, row + 1); // Recur for the next row
            board[row][j] = '.';   // Backtrack
        }
    }
}

// Recursive function to solve the N-Queens problem 2nd variety no.of possible solutions
int nQueens2(vector<vector<char>> &board, int row) {
    int n = board.size();
    if (row == n) {
        printBoard(board); // Print the solution when all rows are filled
        return 1;

    }

    int count = 0;

    for (int j = 0; j < n; j++) { // Try placing a queen in each column
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';   // Place the queen
            count += nQueens2(board, row + 1); // Recur for the next row
            board[row][j] = '.';   // Backtrack
        }
    }
}

// print any one solution 

bool nQueens3(vector<vector<char>> &board, int row) {
    int n = board.size();
    if (row == n) {
        printBoard(board); // Print the solution when all rows are filled
        return true;

    }


    for (int j = 0; j < n; j++) { // Try placing a queen in each column
        if (isSafe(board, row, j)) {
            board[row][j] = 'Q';   // Place the queen
            if(nQueens3(board, row + 1)){
                return true;
            }
                 // Recur for the next row
            board[row][j] = '.';   // Backtrack
        }
    }

    return false;
}

int main() {
    int n = 4; // Size of the chessboard

    // Initialize board with '.'
    vector<vector<char>> board(n, vector<char>(n, '.'));

    // Call nQueens function to find solutions
    nQueens(board, 0);

    return 0;
}
