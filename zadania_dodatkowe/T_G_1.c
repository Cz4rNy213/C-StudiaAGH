#include <stdio.h>

int main(void){
    double a,b,c;
    printf("Podaj długości boków trójkąta oddzielone spacją");
    scanf("%lf %lf %lf", &a, &b, &c);
    double epsilon = 1e-15;
    
    if (a + b > c + epsilon && a + c > b + epsilon && b + c > a + epsilon){
        printf("Da sie");
    }
    else{
        printf("Nie da sie");
    }

    return 0;
}