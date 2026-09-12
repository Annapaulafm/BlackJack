# Blackjack Simplificado 🃏

## Sobre o Projeto
Jogo de Blackjack simplificado em C, onde o usuário joga contra um NPC (computador). O objetivo é chegar o mais perto possível de 21 pontos sem ultrapassar ou fazer 21.

## Regras do Jogo

- O jogador começa com **2 cartas aleatórias**
- A cada rodada, o jogador pode **comprar mais uma carta** ou **parar**
- Se a pontuação chegar exatamente a **21**, o jogador vence automaticamente
- Se a pontuação **ultrapassar 21**, o jogador perde instantaneamente
- O NPC recebe apenas **2 cartas iniciais** e **nunca compra mais cartas** — sua pontuação final é sempre a soma dessas duas cartas

### Valor das Cartas
| Carta | Valor |
|-------|-------|
| 2 a 9 | Valor nominal |
| X (10) | 10 pontos |
| J, Q, K | 10 pontos |
| A (Ás) | 1 ponto |

### Sistema de Pontuação
| Resultado | Pontos |
|-----------|--------|
| Fez 21 | +10 pontos |
| Estourou (>21) | -2 pontos |
| Parou com mais que o NPC | +1 ponto |
| Empatou com o NPC | 0 pontos |
| Parou com menos que o NPC | -1 ponto |

## Como Compilar e Executar

### Usando Makefile (recomendado)
```bash
make run
```

### Manualmente
```bash
gcc MAIN/main.c CARTA/carta.c JOGADOR/jogador.c -o oi
./oi
```

## Estrutura do Projeto
```
├── MAIN/
│   └── main.c
├── CARTA/
│   ├── carta.h
│   └── carta.c
├── JOGADOR/
│   ├── jogador.h
│   └── jogador.c
└── Makefile
```