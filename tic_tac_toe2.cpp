#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'},
                      {'4', '5', '6'},
                      {'7', '8', '9'} };

char currentMarker;
int currentPlayer;

// Function to draw the board
void drawBoard() {
    system("cls"); // Clear screen (Windows only)
    cout << "TIC-TAC-TOE" << endl;
    cout << "Player 1: X  |  Player 2: O" << endl << endl;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    
    return false;
}

// Function to check if the board is full (draw condition)
bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;
    return true;
}

// Function to place a marker on the board
bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false; // Slot already occupied
    }

    board[row][col] = currentMarker;
    return true;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
}

// Main function to start the game
void playGame() {
    currentPlayer = 1;
    currentMarker = 'X';
    
    drawBoard();

    while (true) {
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter a slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid input! Enter a number between 1-9.\n";
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot occupied! Try again.\n";
            continue;
        }

        drawBoard();

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins! 🎉\n";
            break;
        }

        if (isBoardFull()) {
            cout << "It's a draw! 🤝\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    playGame();
    return 0;
}
