// CLEAN CODE HERE. EXPLANATIONS GIVEN ON VSCODE

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int guess,random;
    random= rand()%100+1;
    int attempt=0;
    printf("*****WELCOME TO THE NUMBER GUESSING GAME*****\n");

    do{
        printf("Enter your guess(1-100): ");
        scanf("%d",&guess);
        attempt++;
        if (guess==random){
            printf("You\'ve guessed the correct number in %d attempts.\n", attempt);
        }
        else if(guess>random){
            printf("Guess a smaller number.\n");
        }
        else if(guess<random){
            printf("Guess a bigger number.\n");

        }

    }while(guess!=random);
    return 0;
}
