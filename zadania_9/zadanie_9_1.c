#include <stdlib.h>
#include <stdio.h>
typedef int (*cmp_data_fp)(const void*, const void*);

typedef struct tagVector {
    void *data;
    size_t element_size;
    size_t size;
    size_t capacity;
    cmp_data_fp cmp_data;
} Vector;

// Fukcje "uniwersalne":
int search_in_vector(const void *pkey, const Vector V) {
    int res;
    for(int i=0; i<V.size; ++i) {
        res = V.cmp_data(pkey, (char*)V.data+i*V.element_size);
// Dlaczego w powyższej instrukcji typ pola data w strukturze V 
// jest rzutowany na wskaźnikowy na znak (długości 1 bajta),
// a nie na typ wskaźnikowy na int, skoro dane w tym wektorze są typu int?
// Uzasadnienie:
// Dzięki uniknięciu specyfikacji konkretnego typu danych w tej funkcji,
// funkcja search_in_vector jest funkcją ogólnego przeznaczenia 
// (uniwersalną dla każdego typu danych pamiętanych w wektorze). 
// Rzutowanie na konkretny tym danych w aktualnym wektorze można zrealizować 
// w funkcji wywoływanej w tej instrukcji - funkcji "specjalizowanej", której adres
// jest zapisany w strukturze V w polu cmp_data. 
        if(res == 0) return i;
    }
    return -1;
}
void freeVectorData(Vector *pV) {
    if(pV->data) free(pV->data);
    pV->size = 0;
    pV->capacity = 0;
}

// Funksje "specjalizowane" dla typu danych int:
int cmp_int(const void *p1, const void *p2) {
    int a=*(int*)p1, b=*(int*)p2;
    return b-a;
}

int main(void) {
    int n=5, *p, key=9, found;
    p = (int*)malloc(10*sizeof(int));
    for(int i=0; i<n; ++i) {
        p[i] = i*i;
    }
    Vector V1;
    V1.data = p;
    V1.element_size = sizeof(int);
    V1.size = n;
    V1.capacity = 10;
    V1.cmp_data = cmp_int;
    found = search_in_vector(&key,V1);
    if(found<0) printf("W wektorze nie ma elementu z %d\n", key);
    else        printf("Indeks znalezionego elementu wektora: %d\n",found);
    freeVectorData(&V1);
    return 0;
}