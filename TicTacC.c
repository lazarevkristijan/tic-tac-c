#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printBoard(char board[3][3]);
int emptySpaces(char board[3][3]);
char checkWinner(char board[3][3], char player);
void clearBuffer();
void resetGame(char board[3][3]);
int playerMove(char board[3][3], char player, char *playAgain);

int main(){

    const char PLAYER1 = 'X';
    const char PLAYER2 = 'O';
    char playAgain = 'Y';
    
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '}, 
                        {' ', ' ', ' '}};

    printBoard(board);

    while(playAgain == 'Y'){
        if (playerMove(board, PLAYER1, &playAgain) != 1){
            playerMove(board, PLAYER2, &playAgain);
        }
    }

    printf("Thnaks for playing\n");
    

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
    int row;
    int col;
    
    printf("Player %c make a move\n", player);

    do{
    printf("Choose row: ");
    scanf("%d", &row);
    
    printf("Choose col: ");
    scanf("%d", &col);

    if(board[row][col] != ' ') {
        printf("Invalid move\n");
    }
    }while(board[row][col] != ' ');

    board[row][col] = player;
    printBoard(board);

    if(checkWinner(board, player) == player){
        printf("%c WON!\n", player);
        printf("Play again? (Y/N): ");

        clearBuffer();
        scanf(" %c", playAgain);
        *playAgain = toupper(*playAgain);
        if(*playAgain == 'Y'){
            resetGame(board);
            printf("NEW GAME\n");
        }
        return 1;
    } else if (emptySpaces(board) == 0){
        printf("TIE!");
        printf("Play again? (Y/N): ");

        clearBuffer();
        scanf(" %c", playAgain);
        *playAgain = toupper(*playAgain);
        if(*playAgain == 'Y'){
            resetGame(board);
            printf("NEW GAME\n");
        }
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

    if(board[0][0] != ' ' && board[0][0] == board[0][1] && board[0][0] == board[0][2]){
        return player;
    } else if(board[1][0] != ' ' && board[1][0] == board[1][1] && board[1][0] == board[1][2]){
        return player;
    } else if(board[2][0] != ' ' && board[2][0] == board[2][1] && board[2][0] == board[2][2]){
        return player;
    }else if(board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' '){
        return player;
    } else if(board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' '){
        return player;
    } else if(board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' '){
        return player;
    } else if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' '){
        return player;
    } else if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' '){
        return player;
    }

    return ' ';

}

void clearBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void resetGame(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
// 200 CURR