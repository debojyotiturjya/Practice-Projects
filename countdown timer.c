#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int convert_to_seconds(int hours, int minutes, int seconds) {
    return hours*3600+minutes*60+seconds;
}

void countdown_timer(int total_seconds) {
    int hours,minutes,seconds;

    while(total_seconds>=0) {
        hours=total_seconds/3600;
        int rem=total_seconds%3600;

        minutes=rem/60;
        seconds=rem%60;

        system("cls");

        printf("Countdown Timer: %02d:%02d:%02d\n", hours, minutes, seconds);

        Sleep(1000); //in miliseconds
        total_seconds--;
    }

    printf("Time's up!\n");
}

int main() {
    int hours, minutes, seconds;

    printf("Enter countdown time (max 24 hours):\n");
    printf("Hours   (0~23): "); scanf("%d", &hours);
    printf("Minutes (0~59): "); scanf("%d", &minutes);
    printf("Seconds (0~59): "); scanf("%d", &seconds);

    if (hours<0||hours>=24||minutes<0||minutes>=60||seconds<0||seconds>=60){
        printf("Invalid time input. Please enter values within range.\n");
        return 1;
    }

    int total_seconds = convert_to_seconds(hours, minutes, seconds);
    countdown_timer(total_seconds);

    return 0;
}

