#include <stdlib.h>
#include <stdio.h>

int main(void){
    FILE *file;
    file = fopen("plik_do_odczytu_6_2.txt", "r");
    if (file == NULL){ perror("Nie udało się otworzyć pliku"); fclose(file); return 1;}
    char c, c_next;
    while(1){
        c = getc(file);
        if (c == EOF){ break; }
        switch (c)
        {
        case '*':
            c_next = getc(file);
            if (c_next == EOF){ break; }
            if (c_next == '/'){
                while (1){
                    c = getc(file);
                    if (c == EOF){ break; }
                    if(c == '/'){
                        c_next = getc(file);
                        if (c_next == EOF){ break; }
                        if(c_next == '*'){
                            break;
                        }
                    }
                }
            }else{ putchar(c); }
            break;
        case '/':
            c_next = getc(file);
            if (c_next == EOF){ break; }
            if (c_next == '/'){
                while (1){
                    c = getc(file);
                    if (c == EOF){ break; }
                    if(c == '\n'){
                        putchar(10);
                        break;
                    }
                }
            }
            else{ putchar(c); }
            break;

        default:
            putchar(c);
        }
    }
    return 0;
}