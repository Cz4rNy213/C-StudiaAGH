#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
        void* destination_cpy = (char*)(vec->data);
        void* destination_move = (char*)(vec->data) + vec->element_size;
        const void* source_move = (char*)(vec->data);
        size_t size_move = vec->num_of_elements; 
        memmove(destination_move, source_move, size_move * vec->element_size);
        memcpy(destination_cpy, new_element, vec->element_size);
        vec->num_of_elements++;
        vec->vec_capacity *= 2;
    }
    else{
        void* destination_cpy = (char*)(vec->data);
        void* destination_move = (char*)(vec->data) + vec->element_size;
        const void* source_move = (char*)(vec->data);
        size_t size_move = vec->num_of_elements; 
        memmove(destination_move, source_move, size_move * vec->element_size);
        memcpy(destination_cpy, new_element, vec->element_size);
        vec->num_of_elements++;
    }
}

void dump_data(const Vector vec){
    if (vec.element_size == sizeof(char)){
        for (int i = 0; i < vec.num_of_elements; i++){
            printf("%c  ", *((char*)(vec.data) + i * vec.element_size));
        }
    }else if (vec.element_size == sizeof(int)){
        for (int i = 0; i < vec.num_of_elements; i++){
            printf("%d  ", *((int*)((char*)(vec.data) + i * vec.element_size)));
        }
    }else if (vec.element_size == sizeof(double)){
        for (int i = 0; i < vec.num_of_elements; i++){
            printf("%.2lf  ", *((double*)((char*)(vec.data) + i * vec.element_size)));
        }
    }else{
        printf("Unsupported data type!\n");
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
        void* destination_move = (char*)(vec->data) + (index + 1) * vec->element_size;
        const void* source_move = (char*)(vec->data) + index * vec->element_size;
        size_t size_move = vec->num_of_elements - index;
        void* destination_cpy = (char*)(vec->data) + index * vec->element_size;
        memmove(destination_move, source_move, size_move * vec->element_size);
        memcpy(destination_cpy, new_element, vec->element_size);
        vec->num_of_elements++;
        vec->vec_capacity *= 2;
    }else{
        void* destination_move = (char*)(vec->data) + (index + 1) * vec->element_size;
        const void* source_move = (char*)(vec->data) + index * vec->element_size;
        size_t size_move = vec->num_of_elements - index;
        void* destination_cpy = (char*)(vec->data) + index * vec->element_size;
        memmove(destination_move, source_move, size_move * vec->element_size);
        memcpy(destination_cpy, new_element, vec->element_size);
        vec->num_of_elements++;
    }
}

void erase(Vector* vec, size_t index){
    if (index + 1 > vec->num_of_elements){
        printf("Index out of range!n");
    }else if (index + 1 == vec->num_of_elements){
        vec->num_of_elements--;
    }else{
        void* destination = (char*)(vec->data) + (index) * vec->element_size;
        const void* source = (char*)(vec->data) + (index+1) * vec->element_size;
        memmove(destination, source, (vec->num_of_elements - index - 1) * vec->element_size);
        vec->num_of_elements--;
    }
}

void erase_value(Vector* vec, ){
    
}

//erase() funkcja powinna usunac dany obszar pamieci uzywajac del(), a nastepne elementy przesunac o jedno miejsce w lewo, chyba ze byl to ostatni element

int main(void) {
    // Initialize a vector of doubles
    Vector V1 = init_vector(sizeof(double), 5);

    // Push elements to the front and back
    double first = 1.0, second = 2.0, third = 10.0, four = 2.0, five = 14.0, six = 16.0, seven = 100.0;
    push_front(&V1, &first);
    push_front(&V1, &second);
    push_back(&V1, &third);
    push_back(&V1, &four);
    push_back(&V1, &five);
    push_back(&V1, &six);
    push_front(&V1, &seven);

    // Display the vector's contents
    printf("Original Vector: ");
    dump_data(V1);
    printf("\n");

    // Insert a new element at index 2
    double newElement = 99.9;
    insert(&V1, 2, &newElement);
    printf("Vector after inserting at index 2: ");
    dump_data(V1);
    printf("\n");

    // Erase an element at index 4
    erase(&V1, 4);
    printf("Vector after erasing at index 4: ");
    dump_data(V1);
    printf("\n");

    // Resize the vector
    resize(&V1);
    printf("Vector after resizing: ");
    dump_data(V1);
    printf("\n");

    // Reserve additional capacity
    reserve(&V1, 10);

    // Push new elements to test capacity increase
    double eighth = 7.0, ninth = 8.0;
    push_back(&V1, &eighth);
    push_back(&V1, &ninth);
    printf("Vector after pushing more elements: ");
    dump_data(V1);
    printf("\n");

    // Clear the vector
    clear(&V1);
    printf("Vector after clearing: ");
    dump_data(V1);
    printf("\n");

    return 0;
}