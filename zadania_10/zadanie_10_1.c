#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUF_SIZE   512
#define STR_NO_MAX 10000

typedef struct Strings {
    char *string_address;
    int ilosc;
    struct Strings* next;
} Strings;


int compare(Strings* current, char* string) {
    if (current->string_address == NULL){
        return 1;
    }
    return strcasecmp(current->string_address, string);
}

// Strings* search(Strings* head, char* string){
//     Strings* current = head;
//     while(current != NULL){
//         if (compare(current, string) == 0){
//             return current;
//         }
//         current = current->next;
//     }
//     return NULL;
// }

Strings* searchSpace(Strings* head, char* string){
    Strings* current = head;
    Strings* prev = NULL;
    while(current != NULL && compare(current, string) < 0){
        prev = current;
        current = current->next;
    }
    if (current != NULL && compare(current, string) == 0){
        return current;
    }else{
        return prev;
    }
}

void insert(Strings** head, Strings* prev, char* string, int* str_count){
    Strings* existing_node = searchSpace(*head, string);
    if (existing_node != NULL && compare(existing_node, string) == 0){
        existing_node->ilosc++;
    }else{
        Strings* new_node = (Strings*)malloc(sizeof(Strings));
        new_node->string_address = (char*)malloc(strlen(string) +1);
        strcpy(new_node->string_address, string);
        new_node->ilosc = 1;
        if (prev == NULL){
            new_node->next = *head;
            *head = new_node;
        }
        else{
            new_node->next = prev->next;
            prev->next = new_node;
        }
        (*str_count)++;
    }
}

void printList(Strings* head){
    Strings* current = head;
    while(current != NULL){
        printf("%s %d\n", current->string_address, current->ilosc);
        current = current->next;
    }
}

void printElement(Strings* head, int index){
    Strings* current = head;
    for (int i = 0 ; i < index - 1; i++){
        current = current->next;
    }
    printf("%s %d\n", current->string_address, current->ilosc);
}

void freeList(Strings* head) {
    Strings* current = head;
    while (current != NULL) {
        Strings* next = current->next;
        free(current->string_address);  
        free(current);                  
        current = next;
    }
}

int main(void) {
    char buffer[BUF_SIZE];
    FILE *plik;
    plik = fopen("tekst_linux.txt", "r");
    Strings* head = NULL;
    head = (Strings*)malloc(sizeof(Strings));
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
            Strings* prev = searchSpace(head, dynam_str);
            insert(&head, prev, dynam_str, &str_count);
            token = strtok(NULL, ".,:!?()\t+ \"\n");
        }
    }
    fclose(plik);
    // printList(head);
    int index;
    scanf("%d", &index);
    printElement(head, index);
    freeList(head);
    return 0;
}
