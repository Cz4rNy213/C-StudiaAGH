#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

/* Nalezy uzupelnic o header biblioteki zawierajacy definicja stalej INT_MAX */

#define OCENIAJ 0  // Przed wyslaniem programu do oceny nalezy wartosc tej stalej zmienic na 1 

int main(void) {
    int seed, n;
    if(OCENIAJ == 0) printf("Wpisz wartosc zarodka: ");
    scanf("%d",&seed);
    if(OCENIAJ == 0) printf("Wpisz liczbe generowanych liczb pseudolosowych: ");
    scanf("%d",&n);
    if (n >= INT_MIN && n <= INT_MAX){
        double average;
        int nums[n];
        srand(seed);
        for (int i = 0; i < n; i++){
            nums[i] = (rand() % (999 - 100 + 1) + 100);
        }
        for (int first_digit = 1; first_digit <= 9; first_digit++){
            double counter = 0, sum = 0;
            for (int num = 0; num < n; num++){
                if (floor(nums[num] / 100) == first_digit){
                    counter ++;
                    sum += nums[num];
                }
            }
            average = sum / counter;
            printf("%.2lf ", average);
        }
    }
    

    return 0;
}