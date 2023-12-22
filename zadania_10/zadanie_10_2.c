#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct tagListElement {
    struct tagListElement *next;
    Data                   data;
} ListElement;

typedef struct tagList {
    ListElement *head;
    ListElement *tail;
    int size;
} List;

/* inicjalizacja listy */
void init(List*list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/* Dodawanie danych do listy */
void push_front(List*list, Data data) {
    ListElement* element = (ListElement*)malloc(sizeof(ListElement));
    element->next = list->head;
    element->data = data;
    if(list->head != NULL) {
        list->head=element;
    } else {
        list->head = element;
        list->tail = element;
    }
    list->size++;
}

void push_back(List*list, Data data) {
    ListElement* element = (ListElement*)malloc(sizeof(ListElement));
    element->next= NULL;
    element->data = data;
    if(list->tail != NULL){
        list->tail->next = element;
        list->tail = element;
    } else {
        list->head = element;
        list->tail = element;
    }
    list->size++;
}

/* Usuwanie pierwszego elementu */
void delete_front(List *list){
    ListElement* toDelete;
    if(list->head == NULL) return;
    toDelete = list->head;
    list->head = list->head->next;
    if(list->head == NULL) list->tail = NULL;
    free(toDelete);
    list->size--;
}

/* Zwalnianie całej listy */
void freeList(List *list) {
    while(list->head) {
        delete_front(list);
    }
}

/* Wypisanie zawartości listy */
void dumpList(const List *list) {
    ListElement *curr;
    for(curr=list->head; curr!=NULL; curr=curr->next){
        printf("%d ",curr->data);
    }
    printf("\n");
}

int main(void) {
    List list;
    init(&list);
    for(int i=0; i<10; i++) {
        push_back(&list,i);
        push_front(&list,i);
        
    } 
    dumpList(&list);
 
    for(int i=0; i<5; i++) {
        delete_front(&list);
        push_back(&list,100+i); 
    }
    dumpList(&list);
 
    freeList(&list);
    return 0;
}