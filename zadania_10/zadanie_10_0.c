#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE   512
#define STR_NO_MAX 10000

typedef struct Strings {
    char *string_address;
    int ilosc;
} Strings;


int compare(const void *prev, const void *next) {
    const Strings *ch1 = (const Strings *)(prev);
    const Strings *ch2 = (const Strings *)(next);
    return strcasecmp(ch1->string_address, ch2->string_address);
}

int main(void) {
    char buffer[BUF_SIZE];
    FILE *plik;
    plik = fopen("tekst_linux.txt", "r");
    Strings *strings_array = (Strings *)malloc(STR_NO_MAX * sizeof(Strings));
    if (plik == NULL) {
        printf("Blad w fopen\n");
        exit(1);
    }
    int str_count = 0;
    while (fgets(buffer, BUF_SIZE, plik) != NULL && str_count < STR_NO_MAX) {
        char *token = strtok(buffer, ".,:!?()\t+ \"\n");
        while (token != NULL) {
            char *dynam_str = (char *)malloc(strlen(token) + 1);
            strcpy(dynam_str, token);
            Strings key = {dynam_str, 0};
            Strings *base = bsearch(&key, strings_array, str_count, sizeof(Strings), compare);
            if (base == NULL) {
                strings_array[str_count].string_address = dynam_str;
                strings_array[str_count].ilosc = 1;
                str_count++;
                qsort(strings_array, str_count, sizeof(Strings), compare);
            } else {
                base->ilosc++;
                free(dynam_str);
            }
            token = strtok(NULL, ".,:!?()\t+ \"\n");
        }
    }
    fclose(plik);

    int unique_count = 0;
    int sum = 0;
    for (int i = 0; i < str_count; i++) {
        sum += strings_array[i].ilosc;
    }
    printf("%d %d", str_count, sum);

    for (int i = 0; i < str_count; i++) {
        free(strings_array[i].string_address);
    }
    free(strings_array);
    return 0;
}
