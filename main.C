#include <stdio.h>
#include <string.h> 

int main() {
    char placa[9];
    int tipo;
    float horas, tarifa, horasCobranca, valorBase, desconto = 0, multa = 0, valorFinal;
    char tipoTexto[15];
    int categoriaTempo;

    printf("Informe a placa do veiculo: ");
    scanf("%8s", placa); 
    
    printf("Selecione o tipo do veiculo:\n");
    printf("  1 - Carro\n");
    printf("  2 - Moto\n");
    printf("  3 - Caminhonete\n");
    printf("Opcao: ");
    scanf("%d", &tipo);

    switch(tipo) {
        case 1:
            tarifa = 5.00;
            strcpy(tipoTexto, "Carro");
            break;
        case 2:
            tarifa = 3.00;
            strcpy(tipoTexto, "Moto");
            break;
        case 3:
            tarifa = 8.00;
            strcpy(tipoTexto, "Camionete");
            break;
        default:
            printf("Erro: Tipo de veiculo invalido!\n");
            return 1;
    }

    printf("Informe o tempo de permanencia (em horas): ");
    scanf("%f", &horas);

    
    if (horas < 1.0) {
        horasCobranca = 1.0;
    } else {
        horasCobranca = horas;
    }

    valorBase = tarifa * horasCobranca;

    if (horas > 5.0) {
        desconto = valorBase * 0.10;
    }

    if (horas > 10.0) {
        multa = 20.00;
    }

    valorFinal = valorBase - desconto + multa;

    if (horas <= 5.0) {
        categoriaTempo = 1;
    } else if (horas <= 10.0) {
        categoriaTempo = 2;
    } else {
        categoriaTempo = 3;
    }

    printf("\n============================================\n");
    printf("             COMPROVANTE DE SAIDA\n");
    printf("============================================\n");
    printf("Placa            : %s\n", placa);
    printf("Tipo de veiculo  : %s\n", tipoTexto);
    printf("Tarifa por hora  : R$ %.2f\n", tarifa);
    printf("Tempo registrado : %.2f h\n", horas);
    printf("Horas cobradas   : %.2f h\n", horasCobranca);
    printf("--------------------------------------------\n");
    printf("Valor base       : R$ %.2f\n", valorBase);
    
    if (desconto > 0) {
        printf("Desconto (10%%)   : -R$ %.2f\n", desconto);
    } else {
        printf("Desconto         : Nao aplicavel\n");
    }

    if (multa > 0) {
        printf("Multa (>10h)     : +R$ %.2f\n", multa);
    } else {
        printf("Multa            : Nao aplicavel\n");
    }

    printf("--------------------------------------------\n");
    printf("VALOR FINAL      : R$ %.2f\n", valorFinal);
    printf("============================================\n");
    printf("Observacao: ");

    switch(categoriaTempo) {
        case 1:
            printf("Permanencia normal. Obrigado pela preferencia!\n");
            break;
        case 2:
            printf("Permanencia longa. Desconto de 10%% aplicado!\n");
            break;
        case 3:
            printf("Permanencia superior a 10h. Desconto + multa aplicados.\n");
            break;
    }

    return 0;
}