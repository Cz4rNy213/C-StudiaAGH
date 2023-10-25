#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main(void){
    int a, b, num;
    scanf("%d %d", &a, &b);
    srand(time(NULL));
    num = (rand() % (b - a + 1)) + a;
    printf("%d", num);
    return 0;
}