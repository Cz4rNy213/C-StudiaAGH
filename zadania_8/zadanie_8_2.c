#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//jesli pojawi sie nowy lancuch to wywolujemy funkcje qsort, 

typedef struct strings{
    char* string_adress;
    int ilosc;
}strings;

int compare(const void* prev, const void* next){
    const strings* ch1 = (const strings*)(prev);
    const strings* ch2 = (const strings*)(next);
    return strcmp(ch1->string_adress, ch2->string_adress);
}

int compare_string(const void* prev, const void* next){
    const strings* str1 = (const strings*)(prev);
    const strings* str2 = (const strings*)(next);
    if (str1->ilosc < str2->ilosc){
        return 1;
    }else if (str1->ilosc > str2->ilosc){
        return -1;
    }else{
        return strcmp(str1->string_adress, str2->string_adress);
    }
}

strings* read_array_of_strings(int n, int* actual_size){
    (*actual_size) = 0;
    strings* strings_array = (strings*)malloc(n * sizeof(strings));
    for (int i = 0; i < n; i++){
        char str[100];
        scanf("%99s", str);
        char *dynam_str = (char*)malloc((strlen(str)+1) * sizeof(char));
        strcpy(dynam_str, str);
        strings key = {dynam_str, 0};
        strings* base = bsearch(&key, strings_array, *actual_size, sizeof(strings), compare);
        if (base == NULL){
            strings_array[*actual_size].string_adress = dynam_str;
            strings_array[*actual_size].ilosc = 1;
            (*actual_size)++;
            qsort(strings_array, *actual_size, sizeof(strings), compare_string);
        }else{
            base->ilosc++;
            free(dynam_str);
        }
    }
    return strings_array;
}

void print_string(strings* tab, size_t tab_size){
    for (size_t i = 0; i < tab_size; i++){
        printf("%s\n", tab[i].string_adress);
    }
}

int main(void) {
    int n;
    printf("Wpisz liczbe łańcuchów którą podasz: ");
    scanf("%d", &n);
    int actual_size;
    strings* strings_array = read_array_of_strings(n, &actual_size);
    print_string(strings_array, actual_size);

    for(int j = 0; j < n; j++){
        free(strings_array[j].string_adress);
    }
    free(strings_array);    
    return 0;
}
