#include <stdio.h>

int main(void) {

    char  t0[3][5] = {0};
    char  t1[3][5] = {{'A','l','a'},{'m','a'},{'k','o','t','a'}};
    char  t2[3][5] = {{"Ala"},{"ma"},{"kota"}};
//    char  t2[3][5] = {"Ala","ma","kota"};
    char *t3[3]    = {"Ala","ma","kota"};

// Wstepne wypelnienie tablicy t0:
    char *p;
    for(p=(char*)t0; p<(char*)t0+15; ++p) *p = '_';
// Wpisanie slow do tablicy t0:
    t0[0][0]='A'; t0[0][1]='l'; t0[0][2]='a'; 
    t0[1][0]='m'; t0[1][1]='a';  
    t0[2][0]='k'; t0[2][1]='o'; t0[2][2]='t'; t0[2][3]='a'; 
    
    printf("t0: ");
    for(size_t i = 0; i<3; ++i) {
        for(size_t j = 0; j<5; ++j) {
            printf("%c",t0[i][j]);
        }
    }
    printf("\nt1: ");
    for(size_t i = 0; i<3; ++i) {
        printf("%s ",t1[i]);
    }
    printf("\nt2: ");
    for(size_t i = 0; i<3; ++i) {
        printf("%s ",t2[i]);
    }
    printf("\nt3: ");
    for(size_t i = 0; i<3; ++i) {
        printf("%s ",t3[i]);
    }
    printf("\n");

    printf("Ile bajtow zajmuja tablice: %d %d %d %d\n",sizeof(t0),sizeof(t1),sizeof(t2),sizeof(t3));
    
    char *p_ma = "ma";
    printf("Adresy pod ktorymi jest zpisane slowo \"ma\": \n%p t0,\n%p t1,\n%p t2,\n%p t3,\n%p literal\n", t0[1], t1[1], t2[1], t3[1], p_ma);
    return 0;
}