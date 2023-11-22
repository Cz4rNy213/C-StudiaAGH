#include <stdlib.h>
#include <stdio.h>

int main(void){
    FILE *file;
    file = fopen("plik_do_odczytu_6_2.txt", "w");
    if (file = NULL){ perror("Nie udało się otworzyć pliku"); fclose(file); }
    char c, c_next;
    while(1){
        c = getchar();
        c_next = getchar();

        if(c_next == EOF){ break; }
        switch (c)
        {
        case '*':
            
            break;
        
        case:
            break;
        }
    }


    return 0;
}