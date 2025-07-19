#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "Tic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) cout << "---|---|---\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot-1) / 3;
    int col = (slot-1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return currentPlayer;
    return 0;
}

void swapPlayer() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;

    int winner = 0;
    int slot;

    for (int i = 0; i < 9; i++) {
        drawBoard();
        cout << "Player " << currentPlayer << ", choose your slot (1-9): ";
        cin >> slot;
        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }
        winner = checkWinner();
        if (winner != 0) {
            drawBoard();
            cout << "Player " << winner << " wins!\n";
            break;
        }
        swapPlayer();
    }
    if (winner == 0) {
        drawBoard();
        cout << "It's a draw!\n";
    }
    return 0;
}
