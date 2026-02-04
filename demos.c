#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int p_wins=0;
    int c_wins=0;
    int d=0;

    while(1) {
        int player;
        printf("Enter 1 for Rock, 2 for Paper, 3 for Scissors: ");
        scanf("%d", &player);
        if (player<1||player>3) {
            printf("Invalid choice! Pick 1, 2, or 3\n");
            continue;
        }

        int computer;
        srand(time(0));
        computer=rand()%3+1;

        printf("You chose %d\n", player);
        printf("Computer chose %d\n", computer);

        if(player==computer) {
            printf("Draw\n");
            d=d+1;
            continue;
        }
        else if((player==1 && computer==3)||(player==2 && computer==1)||(player==3 && computer==2)) {
            p_wins=p_wins+1;
            printf("You win this round!\n");
        }
        else {
            c_wins=c_wins+1;
            printf("Computer wins this round!\n");
        }

        if(p_wins>=3) {
            printf("\nYou win the game!\n");
            break;
        }
        else if(c_wins>=3) {
            printf("\nComputer wins the game!\n");
            break;
        }
    }
    printf("\nScore\n");
    printf("You: %d, Computer: %d, Draw: %d\n\n", p_wins, c_wins, d);



    return 0;
}
