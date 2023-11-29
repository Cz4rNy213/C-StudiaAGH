#include <stdio.h>
#include <stdlib.h>

// Program czyta rozmiary i elementy dwóch macierzy, oblicza ich sumę i iloczyn i wyniki wyprowadza na ekran.
// Segment main wywołuje:

// funkcję czytaj - czytającą elementy macierzy o zadanych rozmiarach,
// funkcję dodaj - (uniwersalną, tj. przeznaczoną do do dodawania macierzy o dowolnych, ale takich samych rozmiarach),
// funkcję iloczyn - obliczającą iloczyn macierzy - jeżeli to możliwe, to uniwersalna, dla dowolnych dopuszczalnych rozmiarów,
// funkcję pisz - wyprowadzają elementy macierzy (każdy wiersz w oddzielnej linii).
// Rozmiary macierzy są wczytywane w main.

int** read(int cols, int rows){  
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++){
            printf("Wpisz element w:  %d wierszu, %d kolumnie", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

int** iloczyn(int** matrix1, int** matrix2, int matrix1_rows, int matrix1_cols, int matrix2_rowns, int matrix2_rows){
    if (matrix1_rows == matrix2_rows){
        return 0;
    }
    else{
        return 0;
    }
}

int** dodaj(int** matrix1, int**matrix2, int cols, int rows){
    int** matrix_res = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        matrix_res[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++){
            matrix_res[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix_res;
}


void pisz(int** matrix, int cols, int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    int matrix1_row,matrix1_col, matrix2_rown,  matrix2_row;
    printf("Napisz liczbe wierszy i kolumn pierwszej macierzy, następnie liczbe wierszy i kolumn drugiej macierzy");
    scanf("%d %d %d %d", &matrix1_row, &matrix1_col, &matrix2_rown, &matrix2_row);//do zmiany
    int** matrix1 = read(matrix1_row, matrix1_col);
    int** matrix2 = read(matrix2_rown, matrix2_row);
    int** matrix_suma = dodaj(matrix1, matrix2, matrix1_row, matrix1_col);
    int** matrix_iloczyn = iloczyn(matrix1, matrix2, matrix1_row, matrix1_col, matrix2_rown, matrix2_row);
    pisz(matrix1, matrix1_row, matrix1_col);
    printf("\n");
    pisz(matrix2, matrix2_rown, matrix2_row);
    printf("\n");
    pisz(matrix_suma, matrix1_row, matrix1_col);
    printf("\n");
    pisz(matrix_iloczyn, matrix1_row, matrix2_row);
    printf("\n");


    // Free the allocated memory
    for (int i = 0; i < matrix1_col; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < matrix2_row; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < matrix1_col; i++){
        free(matrix_suma[i]);
    }
    free(matrix_suma);


    return 0;
}

