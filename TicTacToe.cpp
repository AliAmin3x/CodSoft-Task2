#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
        cout << "Tic-Tac-Toe Game" << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------" << endl;
        }
        cout << endl;
    }

    bool isValidMove(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
    }

    bool checkForWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true;
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }

        return false;
    }

    bool checkForDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false; 
                }
            }
        }
        return true; }

    void switchPlayers() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void displayResult() {
        displayBoard();
        if (checkForWin()) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkForDraw()) {
            cout << "It's a draw!" << endl;
        } else {
            cout << "Game in progress. Player " << currentPlayer << "'s turn." << endl;
        }
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;

    do {
        game.displayBoard();
        int row, col;

        do {
            cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column, separated by space): ";
            cin >> row >> col;
        } while (!game.isValidMove(row, col));

        game.makeMove(row, col);

    
        if (game.checkForWin() || game.checkForDraw()) {
            game.displayResult();
            cout << "Do you want to play again? (Y/N): ";
            char playAgain;
            cin >> playAgain;
            if (playAgain != 'Y' && playAgain != 'y') {
                break;
            } else {
                game = TicTacToe();             }
        }

        game.switchPlayers();

    } while (true);

    return 0;
}
