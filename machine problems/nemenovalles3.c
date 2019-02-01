#include <stdio.h>

void display(char table[3][3]);

int main() {
    char tictac[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int col, row = col = 1;
    int checkX, checkY, inputError, finish,
        draw = finish = inputError = checkY = checkX = 0;
    int playerWin[2] = {0, 0}, currentPlayer = 0;
    char item[2] = {'x', 'o'};

    do {
        // Reset Game Board and Current Player
        for (int g = 0; g < 3; g++) {
            for (int h = 0; h < 3; h++) {
                tictac[g][h] = ' ';
            }
        }
        currentPlayer = 0;
        for (int i = 0; i < 2; i++) {
            playerWin[i] = 0;
        }
        do {
            // Asks for input
            do {
                // Checks the current player to print the correct name
                if (currentPlayer) {
                    printf("Player 2, ");
                } else {
                    printf("Player 1, ");
                }

                // Prints error message when there is an input error
                if (inputError) {
                    printf(
                        "You have entered a coordinate that is already filled");
                    inputError = 0;
                }

                // Checks if row entered is correct
                do {
                    if (row < 0 || row > 2) {
                        printf("\nYou have entered an invalid row\n");
                    }
                    printf("\nEnter a row. ");
                    scanf("%i", &row);
                } while (row < 0 || row > 2);

                // Checks if column entered is correct
                do {
                    if (col < 0 || col > 2) {
                        printf("\nYou have entered an invalid column\n");
                    }
                    printf("\nEnter a column. ");
                    scanf("%i", &col);
                } while (col < 0 || col > 2);

                // Checks if selected cell is empty
                if (tictac[row][col] == ' ') {
                    tictac[row][col] = item[currentPlayer];
                } else {
                    inputError = 1;
                }
            } while (inputError);

            display(tictac);

            // Checks if entire row is filled
            for (int x = 0; x < 2; x++) {
                for (int i = 0; i < 3; i++) {
                    // Checks if the first cell is filled
                    if (tictac[i][0] == item[x]) {
                        int j;

                        // If filled, checks if the next columns are filled
                        for (j = 1; j < 3; j++) {
                            if (tictac[i][j] != item[x]) {
                                break;
                            }
                        }

                        if (j == 3) {
                            playerWin[x] = 1;
                        }
                    }
                }

                // Same logic as above but in columns
                for (int k = 0; k < 3; k++) {
                    if (tictac[0][k] == item[x]) {
                        int l;
                        for (l = 1; l < 3; l++) {
                            if (tictac[l][k] != item[x]) {
                                break;
                            }
                        }

                        if (l == 3) {
                            playerWin[x] = 1;
                        }
                    }
                }

                // Checks if diagonals are the same item
                if (tictac[0][0] == item[x]) {
                    int m;
                    for (m = 1; m < 3; m++) {
                        if (tictac[m][m] != item[x]) {
                            break;
                        }
                    }

                    if (m == 3) {
                        playerWin[x] = 1;
                    }
                }

                // Checks if the other diagonal are the same items
                if (tictac[0][2] == item[x]) {
                    int n;
                    if ((tictac[1][1] == tictac[2][0]) &&
                        tictac[1][1] == item[x]) {
                        playerWin[x] = 1;
                    }
                }
            }

            // Checks for draws, continues the game if there are cells that are
            // empty
            draw = 1;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (tictac[x][y] == ' ') {
                        draw = 0;
                        break;
                    }
                }
            }

            // Swaps the current player
            if (currentPlayer) {
                currentPlayer = 0;
            } else {
                currentPlayer = 1;
            }
        } while (!(playerWin[0] || playerWin[1] || draw));

        // Checks if either player has won
        for (int i = 0; i < 2; i++) {
            if (playerWin[i]) {
                printf("Congratulations Player %i for winning!\n", i + 1);
            }
        }

        if (draw && !(playerWin[0] || playerWin[1])) {
            printf("The game ended in a draw\n");
        }

        // Asks the player to play again after a game
        if (playerWin[0] || playerWin[1] || draw) {
            do {
                printf(
                    "\nWould you like to play again?\nPress 1 to continue or 0 "
                    "to end\n");
                scanf("%i", &finish);
            } while (finish < 0 || finish > 1);
        }
    } while (finish);
}

// Displays the table
void display(char table[3][3]) {
    // 201 203 187 188 185 204 205 206 186
    printf("    0   1   2 \n");
    printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c\n", '*', '-', '-', '-', '-', '-', '-',
           '-', '-', '-', '-', '-', '*');
    printf("0 %c %c %c %c %c %c %c\n", '|', table[0][0], '|', table[0][1], '|',
           table[0][2], '|');
    printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c\n", '|', '-', '-', '-', '+', '-', '-',
           '-', '+', '-', '-', '-', '|');
    printf("1 %c %c %c %c %c %c %c\n", '|', table[1][0], '|', table[1][1], '|',
           table[1][2], '|');
    printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c\n", '|', '-', '-', '-', '+', '-', '-',
           '-', '+', '-', '-', '-', '|');
    printf("2 %c %c %c %c %c %c %c\n", '|', table[2][0], '|', table[2][1], '|',
           table[2][2], '|');
    printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c\n", '*', '-', '-', '-', '-', '-', '-',
           '-', '-', '-', '-', '-', '*');
}
