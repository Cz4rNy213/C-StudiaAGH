#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUF_SIZE   512
#define STR_NO_MAX 10000

// typedef struct Strings {
//     char *string_address;
//     int ilosc;
//     struct Strings* next;
// } Strings;


typedef struct tagListElement {
    struct tagListElement *next;
    char* string_address;
    int quantity;
} ListElement;

typedef struct Strings {
    ListElement *head;
    ListElement *tail;
    int size;
} Strings;


/* inicjalizacja listy */
void init(Strings* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int compare(ListElement* current, char* string) {
    if (current == NULL){
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

int searchSpace(Strings* list, char* string){
    ListElement* current = list->head;
    int pos = 0;
    while(current != NULL && compare(current, string) < 0){
        pos++;
        current = current->next; //do dodania za elementem prev
    }
    if (current != NULL && compare(current, string) == 0){
        return (pos + 1); //index do zwiększenia
    }else{
        return (pos); //index poprzednika
    }
}

void insert(Strings* list,char* string, int pos){

    ListElement* current = list->head;
    int i = 0;
    while (current != NULL && i < pos-1){
        current = current->next;;
        i++;
    }
    if(compare(current, string) == 0){
        current->quantity++;
    }else{
        ListElement* new_node = (ListElement*)malloc(sizeof(ListElement));
        ListElement* temp_tail = list->tail;
        new_node->string_address = (char*)malloc(strlen(string) +1);
        strcpy(new_node->string_address, string);
        new_node->quantity = 1;
        if (pos == 0){
            if (list->head == NULL){
            list->head = new_node;
            list->tail = new_node;
            }else{
                new_node->next = list->head;
                list->head = new_node;
            }
        }else {
            new_node->next = current->next;
            current->next = new_node;
            if(pos == list->size){
                list->tail = new_node;
            }
        }
        list->size++;
    }
}

void printList(const Strings *list) {
    ListElement* curr;
    for(curr=list->head; curr!=NULL; curr=curr->next){
        printf("%s %d\n",curr->string_address, curr->quantity);
    }
    printf("\n");
}

void printElement(Strings* list, int index){
    ListElement* current = list->head;
    for (int i = 0 ; i < index - 1; i++){
        current = current->next;
    }
    printf("%s %d\n", current->string_address, current->quantity);
}

/* Usuwanie pierwszego elementu */
void delete_front(Strings *list){
    ListElement* toDelete;
    if(list->head == NULL) return;
    toDelete = list->head;
    list->head = list->head->next;
    if(list->head == NULL) list->tail = NULL;
    free(toDelete);
    list->size--;
}

/* Zwalnianie całej listy */
void freeList(Strings *list) {
    while(list->head) {
        delete_front(list);
    }
}

int main(void) {
    char buffer[BUF_SIZE];
    FILE *plik;
    plik = fopen("tekst_linux.txt", "r");
    Strings list;
    init(&list);
    if (plik == NULL) {
        printf("Blad w fopen\n");
        exit(1);
    }
    while (fgets(buffer, BUF_SIZE, plik) != NULL && (&list)->size < STR_NO_MAX) {
        char *token = strtok(buffer, ".,:!?()\t+ \"\n");
        while (token != NULL) {
            char *dynam_str = (char *)malloc(strlen(token) + 1);
            strcpy(dynam_str, token);
            int pos = searchSpace(&list, dynam_str);
            insert(&list, dynam_str, pos);
            token = strtok(NULL, ".,:!?()\t+ \"\n");
        }
    }
    fclose(plik);
    // printList(&list);
    int index;
    scanf("%d", &index);
    printElement(&list, index);
    freeList(&list);
    return 0;
}
