#include "../CARTA/carta.h"
#include "../JOGADOR/jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 50
#define MAX_CARTAS 10

int main(){
    //GERA NUMERO SEMPRE ALEATORIO
    srand(time(NULL));

    //INICIALIZANDO JOGADOR 1
    TadJogador jogador1;
    char nomeJogador1[MAX];
    printf("Digite o nome do jogador:\n");
    fgets(nomeJogador1, MAX, stdin);
    nomeJogador1[strcspn(nomeJogador1, "\n")] = '\0'; //Tira a quebra de linha do fgets 
    IncializaJogador(&jogador1, nomeJogador1);
    int pontosJogador1 = 0;

    //INICIALIZANDO JOGADOR 2
    TadJogador jogador2;
    char nomeJogador2 [MAX] = "Computador";
    IncializaJogador(&jogador2, nomeJogador2);
    int pontosJogador2 = 0;

    //JOGADOR ESCOLHE O TIPO DE IMPRESSÃO
    int tipoImpressao = EscolhaImpressao();

    //JLOOP PARA JOGAR NOVAMENTE (S - SIM / N - NÃO)
    char jogarNovamente;
    do{
        IncializaJogador(&jogador1, nomeJogador1);
        IncializaJogador(&jogador2, nomeJogador2);
    
        //COMEÇA JOGO - JOGADOR 1
        comecaJogo(&jogador1);

        //COMEÇA JOGO - JOGADOR 2
        comecaJogo(&jogador2);

        //IMPRIME AS CARTAS DE ACORDO COM O TIPO DE IMPRESSÃO ESCOLHIDO
        for(int i = 0; i < 2; i++){
            printf("Suas cartas:\n");
            ImprimeTipo(jogador1.maoJogador[i], tipoImpressao);
        }

        //CALCULANDO A PONTUAÇÃO DA CARTA - JOGADOR 1
        int pontJogador1 = CalculaPontuacao(&jogador1);
        printf("Voce esta com: %d pontos\n", jogador1.pontuacao);

        //CALCULANDO A PONTUAÇÃO DA CARTA - JOGADOR 2
        int pontJogador2 = CalculaPontuacao(&jogador2);
        printf("Computador esta com: %d pontos\n", jogador1.pontuacao);

        //LOGICA DO BLACKJACK
        char comprarNovamente;
        TadCarta cartaComprada;

        if(pontJogador1 == 21){
            //JOGADOR FEZ 21 COM AS DUAS CARTAS INICIAIS
            printf("Parabens voce ganhou!\n");
        }else if (pontJogador1 > 21){
            //JOGADOR ESTOROU COM AS DUAS CARTAS INICIAIS
            printf("Voce estourou e infelizmente perdeu!\n");
        }else{
            //JOGADOR PAROU COM MENOS DE 21 - PODE COMPRAR MAIS CARTAS
            printf("Deseja comprar mais carta?\n");
            printf("S - sim     N - nao\n");
            scanf(" %c", &comprarNovamente);
            
            //CONTINUA COMPRANDO ENQUANTO O JOGADOR QUISER E NÃO ULTRAPASSAR 21
            while ((comprarNovamente == 'S' || comprarNovamente == 's') && pontJogador1 < 21){
                ComprarCarta(&cartaComprada);
                //COLOCA A CARTA NOVA NA PROXIMA POSIÇÃO LIVRE
                jogador1.maoJogador[jogador1.qtdCartas] = cartaComprada;
                jogador1.qtdCartas += 1;
                pontJogador1 = CalculaPontuacao(&jogador1);
                ImprimeTipo(cartaComprada, tipoImpressao);
                printf("Voce esta com: %d\n", jogador1.pontuacao);
                //SE ALCANÇOU OU ULTRAPASSOU 21 ENCERRA O LOOP 
                if (pontJogador1 >= 21){
                    break;
                }
                printf("Deseja comprar mais carta?\n");
                printf("S - sim     N - nao\n");
                scanf(" %c", &comprarNovamente);
            }
        }
            //VERIFICA RESULTADO APÓS JOGADOR PARAR DE COMPRAR 
            if(pontJogador1 == 21){
                printf("--------------------------------\n");
                printf("Parabens voce ganhou!\n");
                printf("--------------------------------\n");
            }else if (pontJogador1 > 21){
                printf("--------------------------------\n");
                printf("Voce estourou e perdeu!\n");
                printf("--------------------------------\n");
            }else{
                printf("--------------------------------\n");     
                printf("Voce parou com %d pontos!\n", pontJogador1);
                printf("--------------------------------\n");
            
        }

        
        //COMPARANDO PONTUAÇÃO DOS JOGADORES 1 E 2 E ATUALIZANDO OS PONTOS
        if (pontJogador1 == 21){        
            //JOGADRO FEZ 21 - GANHA 10 
            pontosJogador1 += 10;
            printf("Voce ganhou 10 pontos!\n");
            printf("Pontuacao Jogador (%s): %d\n", jogador1.nome, pontosJogador1);
            printf("Pontuacao Jogador (%s): %d\n", jogador2.nome, pontosJogador2);
        }else if(pontJogador1 > 21){
            //JOGADOR ESTOUROU - JOGADOR PERDE 2, COMPUTADOR GANHA 2 
            pontosJogador1 -= 2;
            pontosJogador2 += 2;
            printf("Voce perdeu 2 pontos!\n");
            printf("Pontuacao Jogador (%s): %d\n", jogador1.nome, pontosJogador1);
            printf("Pontuacao Jogador (%s): %d\n", jogador2.nome, pontosJogador2);
        }else{
            //JOGADOR PAROU COM MENOS DE 21 - CAMPARA A PONTUAÇÃO DAS CARTAS COM O COMPUTADOR
            if(pontJogador1 > pontJogador2){
                //JOGADOR COM MAISS PONTOS - JOGADOR GANHA 1, COMPUTADOR PERDE 1
                pontosJogador1 += 1;
                pontosJogador2 -= 1;
                printf("Voce ganhou 1 ponto!\n");
                printf("Pontuacao Jogador (%s): %d\n", jogador1.nome, pontosJogador1);
                printf("Pontuacao Jogador (%s): %d\n", jogador2.nome, pontosJogador2);
            }else if (pontJogador1 < pontJogador2){
                //COMPUTADOR COM MAIS PONTOS - JOGADOR PERDE 1, COMPUTADOR GANHA 1
                pontosJogador1 -= 1;
                pontosJogador2 += 1;
                printf("Voce perdeu 1 ponto!\n");
                printf("Pontuacao Jogador (%s): %d\n", jogador1.nome, pontosJogador1);
                printf("Pontuacao Jogador (%s): %d\n", jogador2.nome, pontosJogador2);
            }else{
                //PONTUAÇÕES IGUAIS - NENHUM GANHA PONTO 
                printf("Voces empataram\n");
                printf("Pontuacao Jogador (%s): %d\n", jogador1.nome, pontosJogador1);
                printf("Pontuacao Jogador (%s): %d\n", jogador2.nome, pontosJogador2);
            }
        }
    
        //PERGUNTA SE O JOGADOR QUER JOGAR NOVAMENTE 
        printf("--------------------------------\n");
        printf("Deseja jogar novamente?\n");
        printf("S - sim     N - nao\n");
        scanf(" %c", &jogarNovamente);

    //CONTINUA O LOOP ENQUANTO O JOGADOR QUISER JOGAR NOVAMENTE
    }while(jogarNovamente == 'S' || jogarNovamente == 's');

    //MOSTRA O RESULTADO FINAL APÓS TODAS AS PARTIDAS
    if(pontosJogador1 > pontosJogador2){
        printf("Voce venceu! com %d pontos\n", pontosJogador1);
    }else if (pontosJogador1 < pontosJogador2){
            printf("Voce perdeu! com %d pontos\n", pontosJogador1);
    }else {
        printf("Voces empataram!");
    }
    
    return 0;
}