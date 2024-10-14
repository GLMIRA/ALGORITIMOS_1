#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// recebe oque usuario digitou 
void entrada_dados(char *valor_digitado,int tamanho){

    printf("Digite o cpf a ser Validado,"
    "no formato (111.111.111-11)\n");
    //armazenado o valor digitado no vetor valor_digita que foi passado
    //como referencia 
    fgets(valor_digitado,tamanho,stdin);
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
    // crio um vetor com cpf's invalidos para fazer uma validacao 
    const char *cpfs_invalidos[] = {
        "000.000.000-00", "111.111.111-11", "222.222.222-22",
        "333.333.333-33", "444.444.444-44", "555.555.555-55",
        "666.666.666-66", "777.777.777-77", "888.888.888-88",
        "999.999.999-99"
    };
    // verifico se o cpf digitado esta no meu vetor de cpfs invalidos 
    for(int i =0; i < 10; i++){
        if (strcmp(valor_digitado,cpfs_invalidos[i]) == 0){
            return 0;
        }
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
    return 1; 
}
// aqui transformo o cpf em um array de inteiros 
void transforma_em_vetor_inteiros(char *valor_digitado, int *cpf_a_validar){
    int j = 0 ;

    for(int i = 0; valor_digitado[i] != '\0'; i++){
        if(isdigit(valor_digitado[i])){
            // se o valor digitado_for um numero ele incrementa no vetor 
            // cpf para validar, isso para tirar os caracteres (.-)
            cpf_a_validar[j++] = valor_digitado[i] - '0';
            //como passo o valor digitado e o cpf como ponteiro ele nao precisa 
            // retornar esse vetor dnv assim aliviando o espaço na memoria 
        }
    }
}

// fazendo a primeira conta para validar o primeiro digito 
// para ver como faz a conta acessar o link abaixo 
// https://www.macoratti.net/alg_cpf.htm
int valida_verificador_1(int *cpf_a_validar){
   
    int lista_do_verificador_1[9] = {10,9,8,7,6,5,4,3,2};
    int verificador_1;
    int resultado = 0;
    for(int i = 0;i < 9; i++){
        resultado += lista_do_verificador_1[i] * cpf_a_validar[i];
    }
    verificador_1 = resultado % 11;

    if(verificador_1 < 2){
        verificador_1 = 0;
    }
    else{
        verificador_1 = 11 -verificador_1;
    }
    // Retorna 1 se o dígito verificador for igual, indicando CPF válido
    // o return esta em uma operção ternaria !!!
    return verificador_1 == cpf_a_validar[9] ? 1 : 0;  
}
// fazendo a segunda conta para validar o segundo digito 
// para ver como faz a conta acessar o link abaixo 
// https://www.macoratti.net/alg_cpf.htm
int valida_verificador_2(int *cpf_a_validar){

    int lista_do_verificador_2[10] = {11,10,9,8,7,6,5,4,3,2};
    int resultado = 0 ;
    int verificador_2;

    for(int i = 0; i < 10 ; i++){
        resultado += lista_do_verificador_2[i] * cpf_a_validar[i];
    }
    verificador_2 = resultado % 11;

    if (verificador_2 < 2){
        verificador_2 = 0;
    }
    else{
        verificador_2 = 11 - verificador_2;
    }
    
    // Retorna 1 se o dígito verificador for igual, indicando CPF válido
    // o return esta em uma operção ternaria !!!
    return verificador_2 == cpf_a_validar[10] ? 1 : 0;  
}

void bild_cpf(int *cpf_a_validar,int tamanho){
    for(int i = 0;i < tamanho; i++ ){
        int numero_cpf = rand() % 10;
        cpf_a_validar[i] = numero_cpf;
    }
}

void cpf_to_str(int *cpf_a_validar,char *cpf_string,int tamanho){
    for(int i = 0; i < tamanho; i++){
        cpf_string[i] = '0' + cpf_a_validar[i];
    }
    cpf_string[tamanho] = '\0';
}
int main(){

    //decalaraçao de variaveis 
    char valor_digitado[100];
    char menu;
    int cpf_a_validar[11];
    char cpf_string[12];
    int attempts = 0;
    srand(time(NULL));
    

    do{
        printf("Validador e Criador de CPF\n "
        "digite a opcao desejada\n"
        "[V]alidar, [C]riar,[S]air: ");
        scanf("%c", &menu);
        getchar();

        switch (menu){
        // o primeiro case esta sem break para aceitar tanto v maiusculo
        // tanto minusculo.
        case 'v':
        case 'V':

        while (1){
            // chamada da funçao para o usuario entrar com os dadao 
            entrada_dados(valor_digitado,sizeof(valor_digitado));
            //validando se oque o ususario digitou é um CPF
            if(valida_entrada_de_dados(valor_digitado) == 1){
                // se for um cpf anulo os caracteres (. - ) e transformo em 
                // um vetor de intereos
                transforma_em_vetor_inteiros(valor_digitado, cpf_a_validar);
                // passo o cpf para verificar o primeiro digito 
                // se o resultado da conta for igual ao numero 
                // ao primeiro verificado ele passa pra proxima 
                //condição
                if(valida_verificador_1(cpf_a_validar) == 1){
                    //faço a conta para verificar o segundo digito 
                    if (valida_verificador_2(cpf_a_validar) == 1 ){
                        // se for verdade mostro o valor digitado e passo 
                        // informando que o cpf é valido 
                        printf("O cpf  %s, é valido\n",valor_digitado);
                        break;
                    }else{
                        // se o segundo digito der errado mostro cpf invalido  
                        printf("O cpf %s, é invalido\n",valor_digitado);
                    }
                }else{
                    // se o primeiro digito der errado ja mostro 
                    //cpf invalido tambem 
                    printf("o cpf %s é invalido\n",valor_digitado);
                }
            }else{
                //caso a entrada de dados nao seja valida,
                //o usario tera que entrar novamente como os dados
                printf("valor invalido isso não é um cpf\n"); 
            }
        }
        break;
        case 'c':
        case 'C':
        while(1){
            bild_cpf(cpf_a_validar, 11); // Gera um novo CPF
            attempts++;

            // Se CPF for válido, exibe e sai do loop
            if (valida_verificador_1(cpf_a_validar) == 1 && valida_verificador_2(cpf_a_validar) == 1) {
                cpf_to_str(cpf_a_validar, cpf_string, 11);
                printf("O CPF novo é: %s\n", cpf_string);
                break; // Sai do loop
            }
            if (attempts >= 1000000) {
                printf("Não foi possível gerar um CPF válido após 1.000.000 tentativas.\n");
                break; // Sai do loop se não gerar CPF válido
            }
        }    
        break;

        case 's':
        case 'S':
            printf("\nsaindo\n");
            menu = 0;
        break;
        
        default:
            printf("opcão invalida\n");
        break;
        }


    }while(menu != 0);

    return 0;

}