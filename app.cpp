#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'},
                           {'4', '5', '6'},
                           {'7', '8', '9'} };

void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "| ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void makeMove(char player) {
    int choice;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        choice--;

        int row = choice / SIZE;
        int col = choice % SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

void computerMove() {
    srand(time(0));
    int choice;
    while (true) {
        choice = rand() % 9;
        int row = choice / SIZE;
        int col = choice % SIZE;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = 'O';
            break;
        }
    }
}

int main() {
    char mode;
    cout << "Choose game mode: \n1. Player vs Player (Enter 1)\n2. Player vs Computer (Enter 2)\n";
    cin >> mode;

    if (mode != '1' && mode != '2') {
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    char currentPlayer = 'X';
    displayBoard();

    while (true) {
        if (mode == '1' || currentPlayer == 'X') {
            makeMove(currentPlayer);
        } else {
            computerMove();
        }

        displayBoard();

        if (checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break; 
        }

        if (isDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
