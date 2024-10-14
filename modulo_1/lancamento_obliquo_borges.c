#include <stdio.h>	
#define _USE_MATH_DEFINES										
#include <math.h>



const double pi = 3.14159265;
double tempo,delta_tempo,velocidade_vertical,velocidade_horizontal,velocidade_inical,altura,distancia,gravidade,angulo,resultado;
int escolha;

double formula_cos(double angulo){
    angulo = angulo*(pi/180);
    angulo = cos(angulo);
    return (angulo);
}
double formula_sen(double angulo){
    angulo = sin(angulo*pi/180);
    return (angulo);
}

double formula_velocidade_vertical(double velocidade_inical, double angulo){
    velocidade_vertical = velocidade_inical*angulo;
    return (velocidade_vertical);
}

double formula_tempo_subida(double velocidade_vertical, double gravidade){
    tempo = velocidade_vertical/gravidade;
    return (tempo);
    
}

double formula_velocidade_horizontal(double velocidade_inical, double angulo){
    velocidade_horizontal = velocidade_inical*angulo;
    return (velocidade_horizontal);
}

double formula_altura_maxima(double velocidade_vertical, double gravidade){
    altura = pow(velocidade_vertical,2)/(2*gravidade);
    return (altura);
}

double formula_delta_tempo(double tempo){
    tempo = (tempo*2);
    return (tempo);
}

double formula_distancia(double velocidade_horizontal, double delta_tempo, double angulo){
    distancia = velocidade_horizontal*delta_tempo;
    return(distancia);
}

double main()
{
printf("Caso queira calcular o tempo de subida digite 1, altura maxima 2, alcance 3, tempo total 4\n");
scanf("%d",&escolha);
    switch(escolha)
    {
    case 1:
    printf("Qual o valor da velocidade inical\n");
    scanf("%lf",&velocidade_inical);
    printf("Qual o valor do angulo\n");
    scanf("%lf",&angulo);
    printf("Qual o valor da gravidade\n");
    scanf("%lf",&gravidade);
    angulo = formula_sen(angulo);
    velocidade_vertical = formula_velocidade_vertical(velocidade_inical,angulo);
    tempo = formula_tempo_subida(velocidade_vertical,gravidade);
    printf("O tempo de subida é %.2lf, sua velocidade vertical foi de : %.2lf\n",tempo,velocidade_vertical);
    break;    
    
    case 2:
    printf("Qual o valor da velocidade inical\n");
    scanf("%lf",&velocidade_inical);
    printf("Qual o valor do angulo\n");
    scanf("%lf",&angulo);
    printf("Qual o valor da gravidade\n");
    scanf("%lf",&gravidade);
    angulo = formula_sen(angulo);
    velocidade_vertical = formula_velocidade_vertical(velocidade_inical,angulo);
    altura = formula_altura_maxima(velocidade_vertical,gravidade);
    printf("Resultado é: %.2lf\n",altura);
    break;
    
    case 3:
    printf("Qual o valor da velocidade inical\n");
    scanf("%lf",&velocidade_inical);
    printf("Qual o valor do angulo\n");
    scanf("%lf",&angulo);
    printf("Qual o valor da gravidade\n");
    scanf("%lf",&gravidade);
    angulo = formula_cos(angulo);
    velocidade_horizontal = formula_velocidade_horizontal(velocidade_inical,angulo);
    velocidade_vertical = formula_velocidade_vertical(velocidade_inical,angulo);
    tempo = formula_tempo_subida(velocidade_vertical,gravidade);
    tempo = formula_delta_tempo(tempo);
    distancia = formula_distancia(velocidade_horizontal,tempo,angulo);
    printf("Resultado é: %.2lf\n",distancia);
    break;
    
    }
    return 0;
    }



