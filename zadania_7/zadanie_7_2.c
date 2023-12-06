#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* read_string(){
    char str[100];
    scanf("%99s", str);
    char *dynam_str = (char*)malloc((strlen(str)+1) * sizeof(char));
    strcpy(dynam_str, str);
    return dynam_str;
}

int compare(const void* prev, const void* next){
    const char* ch1 = *(const char**)(prev);
    const char* ch2 = *(const char**)(next);
    return strcmp(ch1, ch2);
}

// void sort(char* tab[], size_t tab_size){
//     int i,j;
//     bool swapped;
//     for (i = 0; i< tab_size; i++){
//         swapped = false;
//         for (j = 0; j<tab_size - i -1; j++){
//             if(*tab[j] > *tab[j+1]){
//                 swap(&tab[j], &tab[j+1]);
//                 swapped = true;
//             }
//         }
//         if(swapped == false){
//             break;
//         }
//     }
// }

void print_string(char* tab[], size_t tab_size){
    for (size_t i = 0; i < tab_size; i++){
        printf("%s\n", tab[i]);
    }
}

int main(void) {
    int n;
    printf("Wpisz liczbe łańcuchów którą podasz: ");
    scanf("%d", &n);
    char** strings_array = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++){
        strings_array[i] = read_string();
    }
    qsort(strings_array, n, sizeof(*strings_array), compare);
    // sort(strings_array, n);
    print_string(strings_array, n);
    for(int j = 0; j < n; j++){
        free(strings_array[j]);
    }
    free(strings_array);    
    return 0;
}
