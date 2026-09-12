#include "carta.h"
#include <stdio.h>

//INICIALIZA TAD CARTA
void Inicializa(TadCarta *carta, int v, char n){
    carta->valor = v;
    carta->naipe = n;
}

//CONEVRETE OS NUMEROS PARA SUAS RESPECTIVAS LETRAS
//1=A, 10=X, 11=J, 12=Q, 13=K
char ConverteValor(TadCarta carta){
    char valor;
    switch (carta.valor)
    {
    case 1:
        valor = 'A';
        break;
    case 10:
        valor = 'X';
        break;
    case 11:
        valor = 'J';
        break;
    case 12:
        valor = 'Q';
        break;
    case 13:
        valor = 'K';
        break;
    default:
        valor = carta.valor + '0';
        break;
    }

    return valor;
}

//IMPRIME CARTA SIMPLES - [valor - naipe]
void ImprimeCartaSimples(TadCarta carta){
    char valorConvertido = ConverteValor(carta);
    printf("[%c - %c]\n", valorConvertido, carta.naipe);
}

//IMPRIME CARTA NO FORMATO ASCII
void ImprimeCartaASCII(TadCarta carta){
    char valorConvertido = ConverteValor(carta);

    printf("+--------+\n");
    printf("| %c      |\n", valorConvertido);
    printf("|        |\n");
    printf("|    %c   |\n", carta.naipe);
    printf("|        |\n");
    printf("|      %c |\n", valorConvertido);
    printf("+--------+\n");
}

//FAZ AS LETRA J, Q, K VALER 10
int TransformaValor(TadCarta carta){
    int valor;
    switch (carta.valor)
    {
    case 11:
        valor = 10;
        break;
    case 12: 
        valor = 10;
        break;
    case 13:
        valor = 10;
        break;
    default:
        valor = carta.valor;
        break;
    }

    return valor;
}

//JOGADOR ESCOLHE O TIPO DE IMPRESSÃO SIMPLES OU ASCII
int EscolhaImpressao(){
    int tipo;

    do{
    printf("Escolha o tipo de impressao:\n");
    printf("1- Carta Simples    2-Carta ASCII\n");
    scanf("%d", &tipo);
    } while (tipo != 1 && tipo != 2);

    return tipo;
}

//IMPRIME DE ACORDO COM O TIPO DE IMPRESSÃO ESCOLHIDO
void ImprimeTipo(TadCarta carta, int tipo){
        if(tipo == 1){
        ImprimeCartaSimples(carta);
    }else{
        ImprimeCartaASCII(carta);
    }
    
}
