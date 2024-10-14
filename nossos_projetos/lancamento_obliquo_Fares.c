#include <stdio.h>
#include <math.h>
const double PI = 3.14159265359;
const double G_TERRA = 9.80665;

void menu(){
    printf("<<< MENU >>>\n 1 - Altura max \n 2 - Tempo de subida \n 3 - Distância percorrida\n >>> ");
}
 
double anguloPraRad(double angulo){
    double AnguloemRad = (PI*angulo)/180; 
    return AnguloemRad;
}

double alturaMax( double veloinicial, double angulo){
    double alturaMax = veloinicial*veloinicial*pow(sin(angulo), 2.0)/2*G_TERRA;
    return alturaMax;
}

double TempodeSubida(double veloinicial, double angulo){
    double tempodesubidaSegundos = veloinicial*sin(anguloPraRad(angulo))/G_TERRA;
    return tempodesubidaSegundos;
}

double alcancehorizontal(double veloinicial, double angulo){
    double alcancehorizontalMetros = pow(veloinicial, 2.0)*sin(2*angulo)/G_TERRA;

    return alcancehorizontalMetros;
}

int main(){
    int Escolha;
    double anguloemgraus, Vinicial, AnguloemRad;

    printf("Theta 0 = "); 
    scanf("%lf", &anguloemgraus);
    AnguloemRad = anguloPraRad(anguloemgraus);

    printf("V0(m/s) = ");
    scanf("%lf", &Vinicial);

    do{
        menu(); 
        scanf("%i", &Escolha);
    }while(Escolha<1 || Escolha>3);

    if(Escolha == 1){
        printf("A altura max do projetil foi de %.2lf m ", alturaMax(Vinicial, AnguloemRad));
    
    }else if(Escolha == 2){
        printf("O tempo de subida do projetil foi de %.2lf s", TempodeSubida(Vinicial, AnguloemRad));

    }else if (Escolha == 3)
    {
        printf("O alcance horizontal do projetil foi de %.2lf m ", alcancehorizontal(Vinicial, AnguloemRad));
    }
 
    return 0;
}