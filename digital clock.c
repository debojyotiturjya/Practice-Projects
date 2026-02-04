//DIGITAL CLOCK

#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include<unistd.h>

int input_format(){
    int format;
    printf("CHOICES: \n1. 24 HOUR FORMAT\n2. 12 HOUR FORMAT (default)\n");
    printf("ENTER CHOICE: ");
    scanf("%d",&format);
    return format;
}

void get_time (char *buffer, int format){
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime);
    current_time= localtime(&rawtime);

    if (format==2){
        strftime(buffer, 50 ,"%I:%M:%S %p",current_time);
    }
    else if(format==1){
        strftime(buffer, 50 ,"%H:%M:%S",current_time);
    }
    else{
        strftime(buffer, 50 ,"%I:%M:%S %p",current_time);
    }
}

void get_date (char *buffer){
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime);
    current_time= localtime(&rawtime);

    strftime(buffer, 50 ,"%A %B %d,%Y",current_time);
}

void clear_screen(){
    #if defined (_WIN64) || defined(_WIN32)
      system("cls"); //jehetu amar windows so ei program er jonno prottek repeatation er pore pura system clear hoye then abr output clean terminal e ashbe
    #else
      system("clear"); //eita faded cz amar system windows er eita probably mac er jonno
    #endif
}


int main(){
    char time[50], date[50];
    int format= input_format();

    while(1){
        get_time(time,format);
        get_date(date);
        clear_screen();
        printf("%s\n",time);
        printf("%s\n",date);
        sleep(1);
    }

}


