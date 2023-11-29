#include <stdio.h>

#define MAX_SIZE 100

void read(int tab[MAX_SIZE], int* size) {
    int i = 0, num = 99;
    while (num != 0 && i < MAX_SIZE){
        scanf("%d", &num);
        tab[i++] = num;
        (*size)++;
    }
}

void average(int tab[MAX_SIZE], int size,  double tab_av[MAX_SIZE], int* increases, int* decreases) {
    float sum = 0, prev_avg = 0;
    for (int i = 0; i < size; i++) {
        sum += tab[i];
        tab_av[i] = (sum / (i + 1));
        if (tab_av[i] > prev_avg) {
            (*increases)++;
        } else if (tab_av[i] < prev_avg) {
            (*decreases)++;
        }
    prev_avg = tab_av[i];
    }
}
void report(double tab_av[MAX_SIZE], int increases, int decreases) {
    for (int i = 0; tab_av[i] > 0 && i < MAX_SIZE; i++) {
        printf("%.2f ", tab_av[i]);
    }
    printf("increases: %d\n", increases);
    printf("decreases: %d\n", decreases);
}

int main() {
    int tab[MAX_SIZE];
    int size = 0;
    double tab_av[MAX_SIZE];
    int increases = 0, decreases = 0;
    read(tab, &size);
    average(tab, size,  tab_av, &increases, &decreases);
    report(tab_av, increases, decreases);
    return 0;
}