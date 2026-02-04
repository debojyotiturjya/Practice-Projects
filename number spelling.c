#include<stdio.h>


void spelling(int n){
    char *ones[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen",
        "fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char *tens[]={"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};

    if (n<20)
        printf("%s",ones[n]);
    else if(n<100){
        printf("%s",tens[n/10]);
        if(n%10){
            printf("-%s",ones[n%10]);
        }
    }
    else if (n<1000){
        printf("%s hundred ",ones[n/100]);
        if (n%100){
            printf("and ");
            spelling (n%100);
        }
    }
    else if(n<20000){
        printf ("%s thousands ",ones[n/1000]);
        if (n%1000){
            spelling(n%1000);
        }
    }
    else if(n<100000){
        printf ("%s thousands ",tens[n/10000]);
        if (n%1000){
            spelling(n%10000);
        }
    }
    else{
        printf("Number too big for the program. We\'re working on it to print such big numbers. Thanks 💝");
    }
}


int main(){
    int n;
    char s;
    printf("Enter your number: ");
    scanf("%d",&n);

    if (n<100000){
        printf("%d= ",n);
        spelling(n);
    }
    else{
        spelling (n);
    }
    return 0;
}
