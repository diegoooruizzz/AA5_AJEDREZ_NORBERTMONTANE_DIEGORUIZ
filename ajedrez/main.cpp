#include <iostream>
#include <string>
#include <cstdlib>

#define TABLERO 8
#define TABLERO_VACIO 0
#define PIEZAS_BLANCAS 1
#define TORRE_BLANCA 2
#define CABALLO_BLANCO 3
#define ALFIL_BLANCO 4
#define REINA_BLANCA 5
#define REY_BLANCO 6
#define PIEZAS_NEGRAS -1
#define TORRE_NEGRA -2
#define CABALLO_NEGRO -3
#define ALFIL_NEGRO -4
#define REINA_NEGRA -5
#define REY_NEGRO -6

// Declaración del tablero
int tablero[TABLERO][TABLERO];


int main() {


	//Inicializar Tablero
	void Inicializartablero(); {
		for (int i = 0; i < TABLERO; i++)
		{
			for (int j = 0; j < TABLERO; j++)
			{
				tablero[i][j] = '*';
			}
		}
	}
	//Inicializar Numeros
	void InicializarNumeros(); {
		for (int i = 0; i < TABLERO; i++) {
			tablero[1][i] = PIEZAS_BLANCAS;
		}
		for (int j = 0; j < TABLERO; j++)
		{
			tablero[-1][j] = PIEZAS_NEGRAS;
		}
	}

	void inicializarPiezas(); {
		//Piezas blancas
		tablero[7][2] = TORRE_BLANCA;
		tablero[7][3] = CABALLO_BLANCO;
		tablero[7][4] = ALFIL_BLANCO;
		tablero[7][5] = REINA_BLANCA;
		tablero[7][6] = REY_BLANCO;
		tablero[7][7] = ALFIL_BLANCO;
		tablero[7][8] = CABALLO_BLANCO;
		tablero[7][9] = TORRE_BLANCA;

		//Piezas negras

		tablero[0][-2] = TORRE_NEGRA;
		tablero[0][-3] = CABALLO_NEGRO;
		tablero[0][-4] = ALFIL_NEGRO;
		tablero[0][-5] = REINA_NEGRA;
		tablero[0][-6] = REY_NEGRO;
		tablero[0][-7] = ALFIL_NEGRO;
		tablero[0][-8] = CABALLO_NEGRO;
		tablero[0][-9] = TORRE_NEGRA;
	}

	void mostrarTablero(); {
		for (int i = 0; i < TABLERO; i++) {
			for (int j = 0; j < TABLERO; j++) {
				printf("%2d ", tablero[i][j]);  // muestra el valor de cada casilla
			}
			printf("\n");
		}
	}

	
	void mostrarTablero();
	
return 0;

}