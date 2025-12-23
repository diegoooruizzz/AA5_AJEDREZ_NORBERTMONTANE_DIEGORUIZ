#include <iostream>
#include <windows.h>
#include "define.h"

using namespace std;

// Definición de la variable global
char tablero[TABLERO_FILAS][TABLERO_COLUMNAS];

void inicializarTablero() {
    // 1. Llenar todo de vacio
    for (int i = 0; i < TABLERO_FILAS; i++) {
        for (int j = 0; j < TABLERO_COLUMNAS; j++) {
            tablero[i][j] = VACIO;
        }
    }

    // 2. Colocar Piezas Negras (Fila 0 / Rank 8)
    // Orden imagen: t h b k q b h t
    tablero[0][0] = TORRE_NEGRA;
    tablero[0][1] = CABALLO_NEGRO;
    tablero[0][2] = ALFIL_NEGRO;
    tablero[0][3] = REY_NEGRO;
    tablero[0][4] = REINA_NEGRA;
    tablero[0][5] = ALFIL_NEGRO;
    tablero[0][6] = CABALLO_NEGRO;
    tablero[0][7] = TORRE_NEGRA;

    // Peones Negros (Fila 1 / Rank 7)
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        tablero[1][j] = PEON_NEGRO;
    }

    // 3. Colocar Piezas Blancas (Fila 7 / Rank 1)
    // Orden imagen: T H B Q K B H T
    tablero[7][0] = TORRE_BLANCA;
    tablero[7][1] = CABALLO_BLANCO;
    tablero[7][2] = ALFIL_BLANCO;
    tablero[7][3] = REINA_BLANCA;
    tablero[7][4] = REY_BLANCO;
    tablero[7][5] = ALFIL_BLANCO;
    tablero[7][6] = CABALLO_BLANCO;
    tablero[7][7] = TORRE_BLANCA;

    // Peones Blancos (Fila 6 / Rank 2)
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        tablero[6][j] = PEON_BLANCO;
    }
}

void mostrarTablero() {
    // Colores para consola Windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    // Imprimir indices de columnas: 1 2 3 ... 8
    SetConsoleTextAttribute(hConsole, 9); // Azul claro
    cout << "   "; // Espacio para el numero de fila
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        cout << j + 1 << " ";
    }
    cout << endl;

    // Imprimir filas
    for (int i = 0; i < TABLERO_FILAS; i++) {
        // Numero de fila a la izquierda (8 bajando a 1)
        SetConsoleTextAttribute(hConsole, 9); // Azul claro
        cout << 8 - i << "  ";

        // Piezas
        for (int j = 0; j < TABLERO_COLUMNAS; j++) {
            char pieza = tablero[i][j];
            
            if (pieza == VACIO) {
                SetConsoleTextAttribute(hConsole, 15); // Blanco/Gris brillante para *
            } else if (isupper(pieza)) {
                // Blancas
                if (pieza == PEON_BLANCO) SetConsoleTextAttribute(hConsole, 15); // Blanco
                else SetConsoleTextAttribute(hConsole, 12); // Rojo/Naranja
            } else {
                // Negras
                if (pieza == PEON_NEGRO) SetConsoleTextAttribute(hConsole, 7); // Gris
                else SetConsoleTextAttribute(hConsole, 11); // Cyan
            }

            cout << pieza << " ";
        }
        cout << endl;
    }
    
    // Reset color
    SetConsoleTextAttribute(hConsole, 7);
}

int main() {
    inicializarTablero();
    mostrarTablero();
    cin.get();
    return 0;
}
