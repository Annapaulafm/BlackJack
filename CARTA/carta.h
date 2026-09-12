#ifndef CARTA_H
#define CARTA_H

typedef struct carta
{
    int valor;
    char naipe;
}TadCarta;

void Inicializa(TadCarta* carta, int v, char n);
char ConverteValor(TadCarta carta);
void ImprimeCarta(TadCarta carta);
void ImprimeCartaASCII(TadCarta carta);
int TransformaValor(TadCarta carta);
int EscolhaImpressao();
void ImprimeTipo(TadCarta carta, int tipo);

#endif