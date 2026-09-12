oi: MAIN/main.c CARTA/carta.c JOGADOR/jogador.c
	gcc MAIN/main.c CARTA/carta.c JOGADOR/jogador.c -o oi

run: oi
	./oi

clean:
	del oi.exe