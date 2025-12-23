#pragma once

// Dimensiones del tablero
#define TABLERO_FILAS 8
#define TABLERO_COLUMNAS 8

// Caracteres del tablero
#define VACIO '*'

// Piezas Blancas (Parte inferior, filas 1-2)
#define PEON_BLANCO 'P'
#define TORRE_BLANCA 'T'
#define CABALLO_BLANCO 'H'
#define ALFIL_BLANCO 'B'
#define REINA_BLANCA 'Q'
#define REY_BLANCO 'K'

// Piezas Negras (Parte superior, filas 7-8)
#define PEON_NEGRO 'p'
#define TORRE_NEGRA 't'
#define CABALLO_NEGRO 'h'
#define ALFIL_NEGRO 'b'
#define REINA_NEGRA 'q'
#define REY_NEGRO 'k'

// Variable global del tablero
extern char tablero[TABLERO_FILAS][TABLERO_COLUMNAS];
