#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int isFull(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char player);

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int winner = 0;

    initializeBoard(board);

    printf("\nWelcome to Tic-Tac-Toe!\n\n");

    while (!winner && !isFull(board)) {
        printBoard(board);
        playerMove(board, currentPlayer);

        if (checkWin(board)) {
            winner = 1;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board);

    if (winner) {
        printf("\nPlayer %c wins!\n", currentPlayer);
    } else {
        printf("\nIt's a draw!\n");
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE; k++) {
                printf("---");
                if (k < SIZE - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int isFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column: 1-3): ", player);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}
