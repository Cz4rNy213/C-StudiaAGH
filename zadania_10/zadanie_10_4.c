#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tagListElement {
 struct tagListElement *next;
 void                  *data;
} ListElement;

typedef void (*ConstDataFp)(const void*);
typedef void (*DataFp)(void*);
typedef int  (*CompareDataFp)(const void*,const void*);

typedef struct tagList {
    ListElement *head;
    ListElement *tail;
    int size;
    ConstDataFp dumpData;
    DataFp freeData;
    CompareDataFp compareData;
} List;

/* inicjalizacja listy */
void init(List *plist) {
    plist->head=NULL;
    plist->tail=NULL;
    plist->size=0;
    plist->dumpData=NULL;
    plist->freeData=NULL;
    plist->compareData=NULL;
}
/* zwolnienie pamięci listy */
void freeList(List *plist) {
    ListElement *current = NULL;
    current = plist->head;
    while(current!=NULL) {
        ListElement *todelete = current;
        current=current->next;
        if(plist->freeData != NULL) plist->freeData(todelete->data);
        free(todelete);
    }
    plist->size=0;
    plist->head=NULL;
    plist->tail=NULL;
}
/* dodaj element na końcu */
void pushBack(List *plist, void *data) {
    ListElement *element = (ListElement*)malloc(sizeof(ListElement));
    element->data=data;
    element->next=0;
    if(plist->tail) plist->tail->next=element;
    plist->tail=element;
    if(!plist->head)plist->head=plist->tail;
    plist->size++;
}
/* dodaj element na początku */
void pushFront(List *plist, void *data) {
    ListElement *element = (ListElement*)malloc(sizeof(ListElement));
    element->data=data;
    element->next=plist->head;
    plist->head=element;
    if(!plist->tail)plist->tail=plist->head;
    plist->size++;
}

/* dodanie danych do listy */
void add(List *plist,void *data) {
    ListElement *element = (ListElement*)malloc(sizeof(ListElement));
    element->next=0;
    element->data=data;
    if(!plist->compareData) { // bez sortowania
        if(plist->tail==0) {
            plist->head=element;
            plist->tail=element;
        } 
        else {
            plist->tail->next=element;
            plist->tail=element;
        }
    }
 /*
    else {            // sortowanie podczas wstwiania
        ListElement*insertionPt = findInsertionPoint(plist,element);
        if(insertionPt==0) {
            element->next=plist->head;
            plist->head=element;
            if(plist->tail==0) plist->tail=plist->head;
        }
        else {
            element->next=insertionPt->next;
            insertionPt->next=element;
        }
    }
    plist->size++;
*/
}


/* czy lista jets pusta */
int isEmpty(const List *plist) {
    return plist->size==0;
}

/* wypisanie zawartości */
void dumpList(const List *plist) {
    ListElement *i;
    for(i=plist->head;i!=0;i=i->next){
        if(plist->dumpData) plist->dumpData(i->data);
        else printf("%p ",i->data);
    }
}


void printString(const void *data) {
    printf("%c ",data);
}

int main(void) {
    List list;
    init(&list);
    list.dumpData=printString;
    add(&list,"Ala");
    add(&list,"ma");
    add(&list,"kota");
    add(&list,"i");
    add(&list,"psa");
    dumpList(&list);
    freeList(&list);
}

int compareString(const void *e1, const void *e2) {
    return strcasecmp((const char*)e1,(const char*)e2);
}
