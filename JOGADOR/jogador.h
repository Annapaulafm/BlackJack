#ifndef JOGADOR_H
#define JOGADOR_H
#define MAX 50
#define MAX_CARTAS 10
#include "../CARTA/carta.h"

typedef struct jogador
{
    char nome[MAX];
    TadCarta maoJogador[MAX_CARTAS];
    int qtdCartas;
    int pontuacao;
}TadJogador;

void IncializaJogador(TadJogador* jogador, char nome[]);
void ComprarCarta(TadCarta *carta);
void comecaJogo(TadJogador* jogador);
int CalculaPontuacao(TadJogador* jogador);

#endif