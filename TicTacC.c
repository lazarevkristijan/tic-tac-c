#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void printBoard(char board[3][3]);
int emptySpaces(char board[3][3]);
char checkWinner(char board[3][3], char player);
void resetGame(char board[3][3]);
int playerMove(char board[3][3], char player, char *playAgain);
void askPlayAgain(char board[3][3], char *playAgain);

int main(){

    const char PLAYER1 = 'X';
    const char PLAYER2 = 'O';
    char playAgain = 'Y';
    
    srand(time(NULL));
    
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '}, 
                        {' ', ' ', ' '}};

    printBoard(board);

    while(playAgain == 'Y'){
        if((rand() % 2) + 1 == 1){
            while(1 == 1){
                if (playerMove(board, PLAYER1, &playAgain) != 1){
                    playerMove(board, PLAYER2, &playAgain);
                } else {
                    break;
                }
            }
        } else {
            while(1 == 1){
                if (playerMove(board, PLAYER2, &playAgain) != 1){
                    playerMove(board, PLAYER1, &playAgain);
                } else {
                    break;
                }
            }
        }
    }
    
    printf("Thanks for playing\n");

    return 0;
}

void printBoard(char board[3][3]){
    printf(" %c  | %c  |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("----|----|----\n");
    printf(" %c  | %c  |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("----|----|----\n");
    printf(" %c  | %c  |  %c \n", board[2][0], board[2][1], board[2][2]);
}

int playerMove(char board[3][3], char player, char *playAgain){
    int row, col;
    
    printf("Player %c make a move\n", player);

    do{
        printf("Choose row: ");
        if(scanf("%d", &row) != 1){
            printf("Invalid input. Enter a number \n");
            while(getchar() != '\n');
            continue;
        };
        
        printf("Choose col: ");
        if(scanf("%d", &col) != 1){
            printf("Invalid input. Enter a number \n");
            while(getchar() != '\n');
            continue;
        };

        if(row > 3 || row < 0 || col > 3 || col < 0 || board[row][col] != ' ') {
            printf("Invalid move\n");
        }
    }while(row > 3 || row < 0 || col > 3 || col < 0 || board[row][col] != ' ');

    board[row][col] = player;
    printBoard(board);

    if(checkWinner(board, player) == player){
        printf("%c WON!\n", player);
        printf("Play again? (Y/N): ");

        askPlayAgain(board, playAgain);
        return 1;
    } else if (emptySpaces(board) == 0){
        printf("TIE!\n");
        printf("Play again? (Y/N): ");

        askPlayAgain(board, playAgain);
        return 1;
    }
    return 0;
}

int emptySpaces(char board[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return 1;
            }
        }
    }

    return 0;
}

char checkWinner(char board[3][3], char player){

    if( board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][0] == board[0][2] ||
        board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][0] == board[1][2] ||
        board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][0] == board[2][2] ||
        board[0][0] != ' ' && board[0][0] == board[1][0] && board[0][0] == board[2][0] ||
        board[0][1] != ' ' && board[0][1] == board[1][1] && board[0][1] == board[2][1] ||
        board[0][2] != ' ' && board[0][2] == board[1][2] && board[0][2] == board[2][2] ||
        board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0] 
    ){
        return player;
    }
    return ' ';

}


void resetGame(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void askPlayAgain(char board[3][3], char *playAgain){
    scanf(" %c", playAgain);
    *playAgain = toupper(*playAgain);
    if(*playAgain == 'Y'){
        resetGame(board);
        printf("NEW GAME\n");
    }
}