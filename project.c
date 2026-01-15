#include<stdio.h>
#include<stdlib.h>

char sq[10] = {'0','1','2','3','4','5','6','7','8','9'};
int in, player;

int checkforwin(void);
void displayboard(void);
void markboard(char m);

int main() {
    int gamestatus;
    char m;
    player = 1;

    do {
        displayboard();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter a number: ", player);
        scanf("%d", &in);

        m = (player == 1) ? 'X' : 'O';
        markboard(m);

        gamestatus = checkforwin();
        player++;

    } while (gamestatus == -1);

    displayboard();

    if (gamestatus == 1) {
        printf("==>> Player %d wins!\n\n", --player);
    } else {
        printf("==>> Game draw!\n\n");
    }

    return 0;
}

int checkforwin(void) {
    if (sq[1]==sq[2] && sq[2]==sq[3]) return 1;
    
    else if (sq[4]==sq[5] && sq[5]==sq[6]) return 1;
    
    else if (sq[7]==sq[8] && sq[8]==sq[9]) return 1;
    
    else if (sq[1]==sq[4] && sq[4]==sq[7]) return 1;
    
    else if (sq[2]==sq[5] && sq[5]==sq[8]) return 1;
    
    else if (sq[3]==sq[6] && sq[6]==sq[9]) return 1;
    
    else if (sq[1]==sq[5] && sq[5]==sq[9]) return 1;
    
    else if (sq[3]==sq[5] && sq[5]==sq[7]) return 1;
    
    else if (sq[1]!='1' && sq[2]!='2' && sq[3]!='3' &&
             sq[4]!='4' && sq[5]!='5' && sq[6]!='6' &&
             sq[7]!='7' && sq[8]!='8' && sq[9]!='9')
        return 0;
    else
        return -1;
}

void displayboard(void) {
	system("cls");
    printf("\n\n\t Tic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", sq[1], sq[2], sq[3]);
    printf("_____|_____|_____\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", sq[4], sq[5], sq[6]);
    printf("_____|_____|_____\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", sq[7], sq[8], sq[9]);
    printf("     |     |     \n");
}

void markboard(char m) {
    if (in == 1 && sq[1] == '1') sq[1] = m;
    
    else if (in == 2 && sq[2] == '2') sq[2] = m;
    
    else if (in == 3 && sq[3] == '3') sq[3] = m;
    
    else if (in == 4 && sq[4] == '4') sq[4] = m;
    
    else if (in == 5 && sq[5] == '5') sq[5] = m;
    
    else if (in == 6 && sq[6] == '6') sq[6] = m;
    
    else if (in == 7 && sq[7] == '7') sq[7] = m;
    
    else if (in == 8 && sq[8] == '8') sq[8] = m;
    
    else if (in == 9 && sq[9] == '9') sq[9] = m;
    else {
        printf("Invalid move!\n");
        player--;
    }
}

