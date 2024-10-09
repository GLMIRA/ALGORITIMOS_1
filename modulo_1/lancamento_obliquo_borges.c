/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

/* primeiro exercicio, aqui ele recebe o tempo do local em segundos e transforma em hora e minutos
float main() {
	float tempolocal,hora,minu,segun;
	  		printf("Digite o tempo em segundos!\n");
                scanf("%f",&tempolocal);
    if(tempolocal > 0){
    minu = tempolocal / 60;            
    hora = minu/ 60;   
        printf("Tempo em horas: %f hora, %f minutos", hora, minu);
    }else{printf("O Tempo não pode ser 0 ou menor !");}
  return 0;
	
}*/
/* isso é uma serie de switch onde seleciona o número de medias que vc quiser 
float main(){
    float n1,n2,n3,r;
    int c;
        printf("Quantos valores tera na média?");
            scanf("%d", &c);
        
    switch (c)
    {
        case 1:
            printf("Digite o primeiro valor:\n");
                scanf("%f", &n1);
                    r = n1/c; 
                        printf("O valor da Média é %f ",r);
        break;
        
        case 2:
            printf("Digite o primeiro valor:\n");
                scanf("%f", &n1);
            printf("Digite o segundo valor:\n");
                scanf("%f", &n2);
                    r = (n1+n2)/c; 
                        printf("O valor da Média é %f ",r);
        break;
        
        case 3:
            printf("Digite o primeiro valor:\n");
                scanf("%f", &n1);
            printf("Digite o segundo valor:\n");
                scanf("%f", &n2);
            printf("Digite o terceiro valor:\n");
                scanf("%f", &n3);
                    r = (n1+n2+n3)/c; 
                        printf("O valor da Média é %f ",r);
        break;
        
        
        
    }
    return 0;
}*/
float main(){
    float velocidade_inicial, velocidade_inicial_y, velocidade_inicial_x, distancia_total_x;
    float distancia_total_y, gravidade, angulo_x, angulo_y, resultado;
    int angulo, tempo, escolha;
        
        printf("Qual será o angulo do lançamento? \n");
            scanf("%d", &angulo);
                switch (angulo)
                {
                    case 30:
                    printf("O que vc quer descobrir, caso seja o tempo de subida digite 1, altura maxima digite 2 e distancia 3:");
                        scanf("%d", &escolha);
                    switch (escolha)
                    {
                        case 1:
                            printf("Qual o valor da velocidade inicial?\n");
                                scanf("%f",&velocidade_inicial);
                            printf("Qual o valor da gravidade?\n");
                                scanf("%f",&gravidade);
                                    velocidade_inicial_y = velocidade_inicial*0.5;
                                        tempo = velocidade_inicial_y/gravidade;
                                            printf("O valor valor do tempo é %d m/s",tempo);
                        break;
                        
                        case 2:
                            printf("Qual o valor da velocidade inicial?\n");
                                scanf("%f",&velocidade_inicial);
                            printf("Qual o valor da gravidade?\n");
                                scanf("%f",&gravidade);
                                    velocidade_inicial_y = velocidade_inicial*0.5;
                                        distancia_total_y = (velocidade_inicial_y*velocidade_inicial_y)/(2*gravidade);
                                            printf("O valor da distancia total y é %f m/s",distancia_total_y);
                        break;
                        
                        case 3:
                            printf("Qual o valor da velocidade inicial?\n");
                                scanf("%f",&velocidade_inicial);
                            printf("Qual o valor da gravidade?\n");
                                scanf("%f",&gravidade);
                                    velocidade_inicial_y = velocidade_inicial*0.5;
                                        tempo = velocidade_inicial_y/gravidade;
                                            velocidade_inicial_x = velocidade_inicial*0.87;
                                                distancia_total_x = velocidade_inicial_x*(tempo*2);
                                                    printf("O valor do alcanse é %f m/s",distancia_total_x);
                    }
                    
                }
                
            }


