#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

const double GRAVIDADE_PADRAO = 9.8;
int menu;
double velocidade_inicial, angulo_lancamento, tempo_especifico;
double vel_horizontal_inicial, vel_vertical_inicial, temp_voo_total;
double altura_maxima, alcance_horizontal, posicao_horizontal, posicao_vertical;

//retorna o angulo em Radianos
double converte_angulo(double angulo_lancamento){

    angulo_lancamento = angulo_lancamento * (M_PI/180);
       
    return angulo_lancamento;
}
// retorna a velocidade vertical inicial
double calcula_componente_velocidade_vertical(double velocidade_inicial, double angulo_lancamento){

    vel_vertical_inicial = velocidade_inicial * sin(angulo_lancamento);

    return vel_vertical_inicial;
}
// retorna a velocidade horizontal inicial 
double calcula_componente_velocidade_horizontal(double velocidade_inicial, double angulo_lancamento){

    vel_horizontal_inicial = velocidade_inicial * cos(angulo_lancamento);
    
    return vel_horizontal_inicial;

}
// calcula o tempo de voo
double calcula_tempo_voo(double vel_vertical_inicial,double GRAVIDADE_PADRAO){

    temp_voo_total = (2*vel_vertical_inicial)/GRAVIDADE_PADRAO;

    return temp_voo_total;
}
//calcula a altura maxima que o projetil pode chegar 
double calcula_altura_maxima(double vel_vertical_inicial,double GRAVIDADE_PADRAO){
    
    altura_maxima = (vel_vertical_inicial * vel_vertical_inicial)/(2*GRAVIDADE_PADRAO);

    return altura_maxima;
}           
//calcula o alcance horizonta que o projetil chega 
double calcula_alcance_horizontal(double velocidade_inicial,double angulo_lancamento,double GRAVIDADE_PADRAO){

    alcance_horizontal = (velocidade_inicial * velocidade_inicial * sin(2* angulo_lancamento))/GRAVIDADE_PADRAO;

    return alcance_horizontal;

}

double calcula_posicao_horizontal_tmp(double vel_horizontal_inicial,double tempo_especifico){

    posicao_horizontal = vel_horizontal_inicial * tempo_especifico;

    return posicao_horizontal;

}
double calcula_posicao_vertical_tmp(double vel_vertical_inicial,double tempo_especifico,double GRAVIDADE_PADRAO){

    posicao_vertical = vel_vertical_inicial * tempo_especifico - 0.5 * GRAVIDADE_PADRAO * tempo_especifico * tempo_especifico;

    return posicao_vertical;
}

void main(){
    do{
        
        printf("Calculo para lancamento obliquo\n"
        "Digite 1- para fazer o calculo:\n "
        "Digite 0- para Sair:\n ");
        scanf("%d",&menu);

        switch (menu)
        {
        case 1:
            printf("ENTRADA DE DADOS\n");
            printf("Digite a velocida inicial (m/s): ");
            scanf("%lf",&velocidade_inicial);
            printf("\nDigite o angulô de lançamento (graus): ");
            scanf("%lf",&angulo_lancamento);
            printf("\nDigite o tempo para calcular as posiçoes (s): ");
            scanf("%lf",&tempo_especifico);

            

            double angulo_lancamento_rad = converte_angulo(angulo_lancamento);
            vel_horizontal_inicial = calcula_componente_velocidade_horizontal(velocidade_inicial,angulo_lancamento_rad);
            vel_vertical_inicial = calcula_componente_velocidade_vertical(velocidade_inicial,angulo_lancamento_rad);
            temp_voo_total = calcula_tempo_voo(vel_vertical_inicial,GRAVIDADE_PADRAO);
            altura_maxima = calcula_altura_maxima(vel_vertical_inicial,GRAVIDADE_PADRAO);
            alcance_horizontal = calcula_alcance_horizontal(velocidade_inicial,angulo_lancamento_rad,GRAVIDADE_PADRAO);
            posicao_horizontal = calcula_posicao_horizontal_tmp(vel_horizontal_inicial,tempo_especifico);
            posicao_vertical = calcula_posicao_vertical_tmp(vel_vertical_inicial,tempo_especifico,GRAVIDADE_PADRAO);

            if(tempo_especifico <= temp_voo_total){
                printf("Posição no tempo %.2f s:\n", tempo_especifico);
                printf("Posição horizontal (x): %.2f m\n", posicao_horizontal);
                printf("Posição vertical (y): %.2f m\n", posicao_vertical);
            } 
            else{
                printf("O tempo %.2f s excede o tempo total de voo.\n", tempo_especifico);
            }

        break;

        case 0: 
            printf("saindo ...");
            menu = 0;
        break;
        
        default:
        printf("opcao invalida ");
        break;
        }



    }while(menu != 0);

}