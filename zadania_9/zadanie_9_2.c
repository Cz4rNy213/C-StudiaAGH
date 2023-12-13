#include <stdlib.h>
#include <stdio.h>

typedef struct Vector{
    void* data; // pointer to vector of elements
    size_t element_size; //size of each element
    size_t num_of_elements; //actual number of elements
    size_t vec_capacity; //means max elements 
}Vector;

Vector init_vector(size_t element_size, size_t capacity){
    Vector vec;
    vec.data = (Vector*)malloc(capacity * element_size);
    vec.element_size = element_size;
    vec.num_of_elements = 0;
    vec.vec_capacity = capacity;
    return vec;
}

void reserve(Vector* vec, size_t capacity){
    if (capacity > vec->vec_capacity){
        vec->data = realloc(vec->data, capacity * vec->element_size);
        vec->vec_capacity = capacity;
    }
}

void resize(Vector* vec){
    vec->data = realloc(vec->data, vec->num_of_elements * vec->element_size);
    vec->vec_capacity = vec->num_of_elements;
}

void push_back(Vector* vec, const void* new_element){
    if (vec->num_of_elements == vec->vec_capacity){
        vec->data = realloc(vec->data, 2 * vec->vec_capacity * vec->element_size);
        void* destination = (char *)(vec->data) + vec->num_of_elements * vec->element_size;
        memcpy(destination, new_element, vec->element_size);
        vec->num_of_elements++;
        vec->vec_capacity *= 2;
    }
    else{
        void* destination = (char*)(vec->data) + vec->num_of_elements * vec->element_size;
        memcpy(destination, new_element, vec->element_size);
        vec->num_of_elements++;
    }
}

void push_front(Vector* vec, const void* new_element){
    if (vec->num_of_elements == vec->vec_capacity){
        vec->data = realloc(vec->data, 2 * vec->vec_capacity * vec->element_size);
        void* destination = (char*)(vec->data);
        memcpy(destination, new_element, vec->element_size);
        vec->num_of_elements++;
        vec->vec_capacity *= 2;
    }
    else{
        void* destination = (char*)(vec->data);
        memcpy(destination, new_element, vec->element_size);
        vec->num_of_elements++;
    }
}

void dump_data(const Vector vec){
    for (int i = 0; i < vec.num_of_elements; i++){
        printf("%p  ", (void*)((char*)(vec.data) + i * vec.element_size));
    }
}

void clear(Vector* vec){
    free(vec->data);
    vec->data = NULL;
    vec->num_of_elements = 0;
}

void insert(Vector* vec, size_t index, const void* new_element){ //dodać nowy element w danym miejscu a te od tego miejsca przesunąć o jedno miejsce dalej 
    if (vec->num_of_elements == vec->vec_capacity){
        vec->data = realloc(vec->data, 2 * vec->vec_capacity * vec->element_size);
        void* destination = (char*)(vec->data) + (index + 1) * vec->element_size;
        const void* source = (char*)(vec->data) + index * vec->element_size;
        size_t size = vec->num_of_elements - index - 1;
        memmove(destination, source, size * vec->element_size);
        memcpy(source, new_element, vec->element_size);
        vec->num_of_elements++;
        vec->vec_capacity *= 2;
    }
}

//erase() funkcja powinna usunac dany obszar pamieci uzywajac del(), a nastepne elementy przesunac o jedno miejsce w lewo, chyba ze byl to ostatni element

int main(void){

    return 0;
}