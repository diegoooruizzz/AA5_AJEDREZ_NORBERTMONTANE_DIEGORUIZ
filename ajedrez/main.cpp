#include <iostream>
#include <string>
#include <cstdlib>

#define TABLERO_VERTICAL 8
#define TABLERO_HORIZONTAL 8
#define TABLERO_VACIO 0
#define PIEZAS_BLANCAS 8
#define TORRE_BLANCA 2
#define CABALLO_BLANCO 3
#define ALFIL_BLANCO 4
#define REINA_BLANCA 5
#define REY_BLANCO 6
#define PIEZAS_NEGRAS -8
#define TORRE_NEGRA -2 
#define CABALLO_NEGRO -3
#define ALFIL_NEGRO -4
#define REINA_NEGRA -5
#define REY_NEGRO -6


#define VACIO '*'
#define PEON_BLANCO 'P'
#define PEON_NEGRO  'p'
#define TORRE_BLANCA 'T'
#define CABALLO_BLANCO 'H'
#define ALFIL_BLANCO 'B'
#define REINA_BLANCA 'Q'
#define REY_BLANCO 'K'

#define TORRE_NEGRA 't'
#define CABALLO_NEGRO 'h'
#define ALFIL_NEGRO 'b'
#define REINA_NEGRA 'q'
#define REY_NEGRO 'k'

// Declaración del tablero
char tablero[TABLERO_VERTICAL][TABLERO_HORIZONTAL];



	//Inicializar Tablero
	void inicializarTablero() {
		for (int i = 0; i < TABLERO_VERTICAL; i++)
		{
			for (int j = 0; j < TABLERO_HORIZONTAL; j++)
			{
				tablero[i][j] = '*';
			}
		}
	}
	
	void mostrarTablero() {
		for (int i = 0; i < TABLERO_VERTICAL; i++)
		{

			for (int j = 0; j < TABLERO_HORIZONTAL; j++)
		{
				std::cout << tablero[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

	//Inicializar Numeros
	void inicializarNumeros() {
		for (int i = 0; i < TABLERO_VERTICAL; i++) {
			tablero[6][i] = 'P';
			
		
		}
		for (int j = 0; j < TABLERO_HORIZONTAL; j++)
		{
			tablero[1][j] = 'p';
			
		}
	}

	void inicializarPiezas() {
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

int main() {

	//Funciones
	
	inicializarTablero();
	inicializarNumeros();
	mostrarTablero();
	
	 
return 0;

}