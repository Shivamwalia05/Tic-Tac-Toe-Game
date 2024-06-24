#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;

class TicTacToe {
private:
    char board[SIZE][SIZE];
    char currentPlayer;

public:
    TicTacToe() {
        int counter = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = '0' + counter++;
            }
        }
        currentPlayer = 'X';
        srand(time(0));
    }

    void displayBoard() const {
        cout << "-------------\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "| ";
            for (int j = 0; j < SIZE; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    bool checkWin(char player) const {
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

    bool isDraw() const {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
            }
        }
        return true;
    }

    void makeMove() {
        int choice;
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 9) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number between 1 and 9.\n";
                continue;
            }

            choice--;

            int row = choice / SIZE;
            int col = choice % SIZE;

            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;
                break;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        }
    }

    void computerMove() {
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

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        char mode;
        cout << "Choose game mode: \n1. Player vs Player (Enter 1)\n2. Player vs Computer (Enter 2)\n";
        cin >> mode;

        if (mode != '1' && mode != '2') {
            cout << "Invalid choice. Exiting.\n";
            return;
        }

        displayBoard();

        while (true) {
            if (mode == '1' || currentPlayer == 'X') {
                makeMove();
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

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
