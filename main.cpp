#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);

int numMoves = 0;

int main() {
    //
    //	PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);

    while (true) {
        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);
        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

void displayBoard(char board[][3]) {

    for (int row = 0; row < 3; row++) {
        cout << "\n-------------\n|";
        for (int col = 0; col < 3; col++) {
            cout << " " << board[row][col] << " |";
        }
    }
    cout << "\n-------------" << endl;
}


void makeAMove(char board[][3], char a) {
    int row, col;
    OUTER:
    cout << "Enter a row (0, 1, 2) for player " << a << "   : ";
    cin >> row;
    cout << "Enter a column (0, 1, 2) for player " << a << ": "; ;
    cin >> col;
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid row/column input" << endl;
        goto OUTER;
    }
    else if (board[row][col] == ' ') {
        board[row][col] = a;
        numMoves++;
    }
    else {
        cout << "This cell is already occupied. Try a different cell" << endl;
        goto OUTER;
    }

}

bool isWon(char c, char board[][3]) {
    if (numMoves > 4) {
        for (int j = 0; j < 3; j++) {

            if (board[j][0] == c && board[j][1] == c && board[j][2] == c)
                return true;

            if (board[0][j] == c && board[1][j] == c && board[2][j] == c)
                return true;
        }

        if (board[1][1] == c) {
            if (board[0][0] == c && board[2][2] == c)
                return true;
            if (board[2][0] == c && board[0][2] == c)
                return true;
        }
    }
    return false;
}

bool isDraw(char board[][3]) {
    if (numMoves == 9) {
        return true;
    }
    return false;
}
