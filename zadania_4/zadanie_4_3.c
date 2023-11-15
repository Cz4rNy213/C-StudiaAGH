#include <stdio.h>
#include <stdlib.h>
#define OCENIAJ  1

double average(int tab[], size_t size){
    double sum = 0 ;
    for (int i = 0; i < size; i++){
        sum += tab[i];
    }
    return sum / size;
}

void print_int_table1D(int tab[], size_t size){
    for (int i =0; i< size; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}

typedef struct TwoTab{
    int* t_small;
    int* t_big;
    int small_index;
    int big_index;
}TwoTab;

// TwoTab seperate(int tab[], size_t size, double average){
//     TwoTab result;
//     result.t_small = (int* )malloc(size * sizeof(int));
//     if(result.t_small == NULL){
//         fprintf(stderr, "Memory allocation for t_small failed");
//         exit(EXIT_FAILURE);
//     }
//     result.t_big = (int* )malloc(size * sizeof(int));
//     if(result.t_big == NULL){
//         fprintf(stderr, "Memory allocation for t_big failed");
//         exit(EXIT_FAILURE);
//     }
//     result.small_index = 0;
//     result.big_index = 0;
//     for(int i = 0; i < size; i++){
//         if(tab[i] < average){
//             result.t_small[result.small_index++] = tab[i];
//         }else{
//             result.t_big[result.big_index++] = tab[i];
//         }
//     }
//     result.t_small = (int* )realloc(result.t_small, (result.small_index + 1) * sizeof(int));
//     result.t_big = (int* )realloc(result.t_big, (result.big_index + 1) * sizeof(int));
//     return result;
// }

void seperate(int tab[], int tabsmall[], int tabbig[], size_t size, double average, int* size1, int* size2){
    for(int i = 0; i < size; i++){
        if(tab[i] < average){
            tabsmall[(*size1)++] = tab[i];
        }else{
            tabbig[(*size2)++] = tab[i];
        }
    }
}



int main(void) {
    int seed, max, size;
    if(OCENIAJ == 0) printf("Wpisz seed, górną granicę domknietego przedziału losowanych liczb i dlugosc tablicy: ");
    scanf("%d %d %d",&seed,&max,&size);
    srand(seed);
    int tab[size];
    for(int i  = 0; i< size; i++){
        int rand1 = (rand() % (max+1));
        int rand2 = (rand() % (max+1));
        // printf("rand1 i rand2  %d   %d\n",rand1, rand2);
        tab[i] = (rand1 * rand2);
        // printf("tab i %d    \n", tab[i]);
    }
    int tab1[size];
    int tab2[size];
    int size1 = 0, size2 = 0;
    seperate(tab, tab1, tab2, size, average(tab, size), &size1, &size2);

    printf("%.2lf\n", average(tab, size));
    print_int_table1D(tab1, size1);
    printf("%.2lf\n", average(tab1, size1));
    print_int_table1D(tab2, size2);
    printf("%.2lf\n", average(tab2, size2));


    // printf("%.2lf\n", average(tab, size));
    // TwoTab result = seperate(tab, size, average(tab, size));
    // print_int_table1D(result.t_small, result.small_index);
    // printf("%.2lf\n", average(result.t_small, result.small_index));
    // print_int_table1D(result.t_big, result.big_index);
    // printf("%.2lf\n", average(result.t_big, result.big_index));
    // free(result.t_small);
    // free(result.t_big);
    return 0;
}