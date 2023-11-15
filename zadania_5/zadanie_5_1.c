#include <stdio.h>
#include <math.h>

double f(double x){
    return 1/((x-0.5)*(x-0.5)+0.01);
}

double simpson(double h, double a, double c, double b) {
    return h * (f(a) + 4 * f(c) + f(b)) / 6;
}


double calculus(double a, double c, double b, int * level, double d){
    double S = simpson(b-a, a, (a+b)/2, b);
    double S1 = simpson(c-a, a, (a+c)/2, c);
    double S2 = simpson(b-c, c, (b+c)/2, b);
    if(fabs(S1 + S2 - S) < d){
        return S;
    }else{
        if((*level) == 10){
            return NAN;
        }else{
        (*level)++;
        double S1_recursive = calculus(a, (a+c)/2, c, level, d/2);
        double S2_recursive = calculus(c, (c+b)/2, b, level, d/2);
        (*level)--;
        return S1_recursive + S2_recursive;
        }
    }
}


int main(void){
    //d-dopuszczalny błąd
    double a, b, d;
    printf("Wprowadź granice dolna granice przedziału całkowania, po spacji górną i po spacji dopuszczalny błąd");
    scanf("%lf %lf %lf",&a, &b, &d);
    double x;
    int level = 0;
    double calc = calculus(a, (a+b)/2, b, &level, d);
    printf("Wartośc całki: %.3lf", calc);


    return 0;
}