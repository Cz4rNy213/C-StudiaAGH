#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#define KOD_MIN  'A'
#define KOD_MAX  'z'
#define ALPHABET_SIZE 57

void checkAndCounter(int ch, int tk[KOD_MAX - KOD_MIN + 1]){
    if ((ch >= KOD_MIN) && (ch <= KOD_MAX)){
        tk[ch - KOD_MIN]++;
    }
}

void findMax(int tk[KOD_MAX - KOD_MIN + 1]){
    int max = 0;
    for (int i = 0; i < KOD_MAX - KOD_MIN + 1; i++){
        if (tk[i] > max){
            max = tk[i];
        }
    }
    printf("%d ",max);
    for (int j = 0; j < KOD_MAX - KOD_MIN + 1; j++){
        if (tk[j] == max){
            putchar(j+KOD_MIN);
            printf(" ");
        }
    }
}

int main(void){
    int tk[KOD_MAX - KOD_MIN + 1] = {0};
    int ch;
    while((ch = getchar()) != EOF){ //nie zapomnieć kliknąć CTRL + D, po skończeniu wpisywania inputu
        checkAndCounter(ch, tk);
    }
    findMax(tk);
    return 0;
}