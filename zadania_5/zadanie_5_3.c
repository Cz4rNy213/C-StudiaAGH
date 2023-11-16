#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> 
#define N 4             // liczba lancuchow
#define STR_LEN_MAX 100 // maksymalna dlugosc lancucha (liczona z '\0')

void update_array(char * tab[], int last_element_counter){
    char str[STR_LEN_MAX];
    scanf("%99s", str);
    char * dynam_str = (char *)malloc((strlen(str)+1) * sizeof(char));
    strcpy(dynam_str, str);
    tab[(last_element_counter)] = dynam_str;
}

void swap(char** prev, char** next){
    char* temp = *prev;
    *prev = *next;
    *next = temp;
}

void sort(char* tab[], size_t tab_size){
    int i,j;
    bool swapped;
    for (i = 0; i< tab_size; i++){
        swapped = false;
        for (j = 0; j<tab_size - i -1; j++){
            if(tolower(*tab[j]) > tolower(*tab[j+1])){
                swap(&tab[j], &tab[j+1]);
                swapped = true;
            }else if(tolower(*tab[j]) == tolower(*tab[j+1])){
                if(strlen(tab[j]) > strlen(tab[j+1])){
                    swap(&tab[j], &tab[j+1]);
                    swapped = true;
                }
            }
        }
        if(swapped == false){
            break;
        }
    }
}

void print_string(char* tab[], size_t tab_size){
    for (size_t i = 0; i < tab_size; i++){
        printf("%s ", tab[i]);
    }
}



int main(void) {
    char** strings_array = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++){
        update_array(strings_array, i);
    }
    sort(strings_array, N);
    print_string(strings_array, N);
    for(int j = 0; j < N; j++){
        free(strings_array[j]);
    }
    free(strings_array);    
    return 0;
}
