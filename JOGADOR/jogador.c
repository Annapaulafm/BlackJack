#include "jogador.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//INICIALIZA O TAD JOGADOR
void IncializaJogador(TadJogador* jogador, char nome[]){
    strcpy(jogador->nome, nome);
    jogador->pontuacao = 0;
    jogador->qtdCartas = 0;
    
    for(int i = 0; i < MAX_CARTAS; i++){
        Inicializa(&jogador->maoJogador[i], 0, ' ');
    }
}

//FUNÇÃO QUE GERA AS CARTAS ALEATORIAS E QUE USAMOS PARA COMPRAR CARTA
void ComprarCarta(TadCarta *carta){
    int valor = rand() % 13 + 1;     //GERA NUMEROS ALEATÓRIAS DE 1 a 13
    char vNaipe[4] = {'C', 'E', 'P', 'O'};
    char naipe = vNaipe[rand() % 4];  //0 = C, 1 = E, 2 = P, 3 = O
    Inicializa(carta, valor, naipe);
}

//FUNÇÃO QUE COMEÇA O JOGO
//COMPRA DUAS CARTAS ALEATÓRIAS PARA O JOGADOR
void comecaJogo(TadJogador* jogador){
    TadCarta compraCarta;
    for(int i = 0; i < 2; i++){
        ComprarCarta(&compraCarta);
        jogador->maoJogador[i] = compraCarta;
        jogador->qtdCartas ++;
    }
}

//CALCULA A PONTUÇÃO DO JOGADOR
//SOMA AS CARTAS DA MÃO DO JOGADOR
int CalculaPontuacao(TadJogador* jogador){
    jogador->pontuacao = 0;     //zera a pontuação sempre, para não acomular e somar errado
    for(int i = 0; i < jogador->qtdCartas; i++){
        int valor = TransformaValor(jogador->maoJogador[i]);
        jogador->pontuacao += valor;
    }
    return jogador->pontuacao;
}