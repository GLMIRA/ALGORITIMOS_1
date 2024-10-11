#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// recebe oque usuario digitou 
void entrada_dados(char *valor_digitado,int tamanho){

    printf("Digite o cpf a ser Validado,"
    "no formato (111.111.111-11)");
    //armazenado o valor digitado no vetor valor_digita que foi passado
    //como referencia 
    fgets(valor_digitado,sizeof(valor_digitado),stdin);
    //removendo o carecter \n 
    valor_digitado[strcspn(valor_digitado,"\n")]= 0;

}
//valida se oque o ususario digitou é um cpf
int valida_entrada_de_dados(char *valor_digitado){
    //removendo o carcter de quebra de linha que esta na string 
    valor_digitado[strcspn(valor_digitado, "\n")] = 0 ;

    // valida se totaliza 14 caracteres 
    if(strlen(valor_digitado) != 14 ){
        return 0;
    }

    //for que valida se a variavel esta dentro 
    //dos paremetros esperados ex:(123.456.789-11)

    //funcao strlen(verifica o tamnho da string, funçao 
    // da lib string.h)
    for(int i = 0; i < strlen(valor_digitado); i++){
        //se nas posiçoes 3 e 7 tem um .
        if(i == 3 || i == 7){
            if(valor_digitado[i] != '.') return 0;
        }
        // se na posiçao 11 tem um -
        else if(i == 11){
            if(valor_digitado[i] != '-') return 0;
        }
        //valida se todos outros caracteres sao digitos 
        else{
            if(!isdigit(valor_digitado[i])) return 0;
        }
    }
}



int main(){

    //decalaraçao de variaveis 

    char valor_digitado[100];
    char menu;
    int loop = 1;
    int cpf_a_validar[14];

    do{
        printf("Validador e Criador de CPF\n "
        "digite a opcao desejada\n"
        "[V]alidar, [C]riar: ");
        scanf("%c",&menu);

        switch (menu){

        case 'v':

        while (loop == 1){
            // chamada da funçao para o usuario entrar com os dadao 
            entrada_dados(valor_digitado,sizeof(valor_digitado));

            if(valida_entrada_de_dados(valor_digitado)){
                

            }
            else{
                //caso a entrada de dados nao seja valida,
                //o usario tera que entrar novamnete como os dados 
                entrada_dados(valor_digitado,sizeof(valor_digitado));
            }
        }
        break;
        
        default:
            break;
        }


    }while(menu != 0);

    return 0;

}