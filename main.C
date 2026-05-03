#include <stdio.h>
#include <locale.h>
int main()
{
    int idade;
    int valido = 0 ;
    char prox_caractere;
    
    while (valido == 0 ){
    printf("Digite a sua idade atual, você deve utilizar numeros inteiros: ");

    int status_scanf = scanf("%d", &idade);
    prox_caractere = getchar();  
    
    if (status_scanf == 1 && prox_caractere == '\n'  ){
        valido = 1;
    }else {
        printf("[ERRO] O tipo de entrada que você utilizou é invalida, o programa exige numeros inteiros. \\n\\n");
        
        char lixo;
        while((lixo = getchar()) != '\n' && lixo != EOF){

        }
    }
};

    if (idade >= 18 && idade < 60){
        printf("Você é um adulto e esta apto para trabalhar");
    }else if(idade <18){
        printf("Você é adolescente e criança, se concentre em estudar para ter uma boa graduação");
    }else{
        printf("Você já esta idoso não seria melhor se aposentar? ");
    
    }
    return 0;
}