#include <stdio.h>
#include <stdlib.h>

#define OCENIAJ 1  // Przed wyslaniem programu do oceny nalezy wartosc tej stalej zmienic na 1 

int main(void) {
    int seed, n;
    if(OCENIAJ == 0) printf("Wpisz wartosc zarodka: ");
    scanf("%d",&seed);
    if(OCENIAJ == 0) printf("Wpisz liczbe generowanych liczb pseudolosowych: ");
    scanf("%d",&n);
    srand(seed);
    int nums[n];
    if (n < 100){
        for (int i = 0; i < n; i++){
            nums[i] = rand();
        }
        for (int l = (sizeof(nums) / sizeof(nums[0])) - 1; l >= 0; l--){
            printf("%d ", nums[l]);
        }
    }
    return 0;
}