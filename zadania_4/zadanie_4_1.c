#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OCENIAJ 1  // Przed wyslaniem programu do oceny nalezy wartosc tej stalej zmienic na 1 
void swap(int* prev, int* next){
    int temp = *prev;
    *prev = *next;
    *next = temp;
}

void bubbleSort(int tab[], int size){
    int i, j;
    bool swapped;
    for (i = 0; i < size; i ++){
        swapped = false;
        for (j = 0; j < size - i - 1; j++){
            if (tab[j] > tab[j+1]){
                swap(&tab[j], &tab[j+1]);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
}


int main(void) {
    int n, seed, indx;
    if(OCENIAJ == 0) printf("Wpisz rozmiar tablicy: ");
    scanf("%d",&n);
    if(OCENIAJ == 0) printf("Wpisz wartosc zarodka: ");
    scanf("%d",&seed);
    if(OCENIAJ == 0) printf("Wpisz indeks wypiywanego elementu: ");
    scanf("%d",&indx);
    int tab[n];
    srand(seed);
    for (int i = 0; i < n; i++){
        tab[i] = rand();
    }
    bubbleSort(tab, n);
    if (indx >= 0){
        printf("%d", tab[n - indx - 1]);
    }else{
        printf("Index < 0");
    }
    return 0;
}