#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** read_array_of_strings(int n, int tab[n]){
    int actual_size = 0;
    char** strings_array = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++){
        char str[100];
        scanf("%99s", str);
        char *dynam_str = (char*)malloc((strlen(str)+1) * sizeof(char));
        strcpy(dynam_str, str);
        for(int j = 0; j < actual_size; j++){
            if (strcpy(strings_array[j], ))
        }
        strings_array[i] = dynam_str;
        actual_size++;
    }

    return strings_array;
}

int compare(const void* prev, const void* next){
    const char* ch1 = *(const char**)(prev);
    const char* ch2 = *(const char**)(next);
    return strcmp(ch1, ch2);
}

void print_string(char** tab, size_t tab_size){
    for (size_t i = 0; i < tab_size; i++){
        printf("%s\n", tab[i]);
    }
}

int main(void) {
    int n;
    // printf("Wpisz liczbe łańcuchów którą podasz: ");
    scanf("%d", &n);
    int tablica_krotnosci[5] = {0};
    char** strings_array = read_array_of_strings(n, tablica_krotnosci);
    qsort(strings_array, n, sizeof(*strings_array), compare);
    // sort(strings_array, n);
    print_string(strings_array, n);
    for(int j = 0; j < n; j++){
        free(strings_array[j]);
    }
    free(strings_array);    
    return 0;
}
