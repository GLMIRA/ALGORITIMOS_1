#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float GRAVIDADE_PADRAO = 9.8;
double function_decompoem_vleocidade(double velocidade, double angulo){
       
        if(angulo == 0) 
}

void main(){

    int menu;
    double velocidade_projetil;
    double angulo_projetil;
    double gravidade_dada_user;
    double angulo;

    do{

        printf("seja bemvindo ao calculo de lancamento obliquo");
        printf("pro favor digite a opcao desejada\n"
              "digite -1 para usar a gravidade padrao(9,8) e pi (3,14)\n"
              "digite -2 para passar os seus dados de gravidade e pi ");
              scanf("%f",&menu);

        switch (menu){
        case 1:
                printf("digite seu angulo");
                scanf("%f",&angulo);

        break;
        
        default:
        break;
        }


    }while(menu == 0);

}