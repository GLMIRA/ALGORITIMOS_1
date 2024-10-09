#include <stdio.h>
#include <math.h>
const double PI = 3.14159265359;



double anguloPraRad(double angulo){
    double AnguloemRad = (PI*angulo)/180; 
    printf("%lf", AnguloemRad);
    return AnguloemRad;
}

int main(){

    double teste;

    printf(">>>");
    scanf("%lf",&teste);
    anguloPraRad(teste);
    
    return 0;
}