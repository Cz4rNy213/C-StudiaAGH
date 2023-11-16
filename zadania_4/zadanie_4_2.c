#include <stdio.h>

#define OCENIAJ 0 // Przed wyslaniem programu do oceny nalezy wartosc tej stalej zmienic na 1 
#define SIZE   10  // rozmiar tablicy

void right(int tab[], int move){
    while (move > 0){
        for (int i = SIZE - 1; i > 0; i--){
            tab[i] =  tab[i - 1];
        }
    tab[0] = -2;
    move --;
    }
}

void left(int tab[], int move){
    while (move > 0){
        for (int i = 0; i < SIZE - 1; i++){
            tab[i] =  tab[i + 1];
        }
    tab[SIZE - 1] = -1;
    move --;
    }
}

int main(void) {
    int tab[SIZE] = {10,11,12,13,14,15,16,17,18,19};
    int move_r, move_l;
    if(OCENIAJ == 0) printf("Wpisz wielkosc przesuniecia w prawo: ");
    scanf("%d",&move_r);
    if(OCENIAJ == 0) printf("Wpisz wielkosc przesuniecia w lewo: ");
    scanf("%d",&move_l);
    right(tab, move_r);
    left(tab, move_l);
    for (int x = 0; x < SIZE; x++){
        printf("%d  ", tab[x]);
    }
    return 0;
}