#include <iostream>
#include <cctype>
#include <cstdlib>
#include "define.h"
#include "inicializacion.h"

// Tablero global
char tablero[TABLERO_FILAS][TABLERO_COLUMNAS];
bool turnoBlancas = true;

void inicializarTablero() {
    // Llenar todo de VACIO
    for (int i = 0; i < TABLERO_FILAS; i++) {
        for (int j = 0; j < TABLERO_COLUMNAS; j++) {
            tablero[i][j] = VACIO;
        }
    }

    // Negras fila 0
    tablero[0][0] = TORRE_NEGRA;
    tablero[0][1] = CABALLO_NEGRO;
    tablero[0][2] = ALFIL_NEGRO;
    tablero[0][3] = REY_NEGRO;
    tablero[0][4] = REINA_NEGRA;
    tablero[0][5] = ALFIL_NEGRO;
    tablero[0][6] = CABALLO_NEGRO;
    tablero[0][7] = TORRE_NEGRA;

    // Blancas fila 7
    tablero[7][0] = TORRE_BLANCA;
    tablero[7][1] = CABALLO_BLANCO;
    tablero[7][2] = ALFIL_BLANCO;
    tablero[7][3] = REINA_BLANCA;
    tablero[7][4] = REY_BLANCO;
    tablero[7][5] = ALFIL_BLANCO;
    tablero[7][6] = CABALLO_BLANCO;
    tablero[7][7] = TORRE_BLANCA;

    // Peones negros fila 1
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        tablero[1][j] = PEON_NEGRO;
    }



    // Peones blancos fila 6
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        tablero[6][j] = PEON_BLANCO;
    }
}

void mostrarTablero() {
    // Columnas
    std::cout << "   ";
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        std::cout << j + 1 << " ";
    }
    std::cout << std::endl;

    // Filas (8 a 1)
    for (int i = 0; i < TABLERO_FILAS; i++) {
        std::cout << 8 - i << "  ";
        for (int j = 0; j < TABLERO_COLUMNAS; j++) {
            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Comprueba si pieza es del color correcto
bool esMiPieza(char pieza) {
    if (turnoBlancas)
        return std::isupper(pieza);
    return std::islower(pieza);
}

// PEÓN: 1 adelante o diagonal (solo si come)
bool peonValido(int fO, int cO, int fD, int cD) {
    char pieza = tablero[fO][cO];
    char destino = tablero[fD][cD];
    int difFila = fD - fO;
    int difCol = std::abs(cD - cO);

    // Blancas (hacia arriba)
    if (pieza == PEON_BLANCO) {
        if (difCol == 0 && difFila == -1 && destino == VACIO)
            return true;  // Adelante
        if (difFila == -1 && difCol == 1 && destino != VACIO && std::islower(destino))
            return true; // Come
    }
    // Negras (hacia abajo)
    else if (pieza == PEON_NEGRO) {
        if (difCol == 0 && difFila == 1 && destino == VACIO)
            return true;   // Adelante
        if (difFila == 1 && difCol == 1 && destino != VACIO && std::isupper(destino))
            return true;  // Come
    }
    return false;
}

// Movimiento válido según pieza
bool esMovimientoValido(int fO, int cO, int fD, int cD) {
    // Básico
    if (fO < 0 || fO >= 8 || cO < 0 || cO >= 8 || fD < 0 || fD >= 8 || cD < 0 || cD >= 8) return false;
    if (fO == fD && cO == cD) return false;

    char pieza = tablero[fO][cO];
    char destino = tablero[fD][cD];

    // No hay pieza, no es mía, capturo propia
    if (pieza == VACIO || !esMiPieza(pieza)) return false;
    if (destino != VACIO && esMiPieza(destino)) return false;

    // Por tipo de pieza
    switch (std::toupper(pieza)) {
    case 'P':
        return peonValido(fO, cO, fD, cD);
    case 'T':
        return (fO == fD || cO == cD);  // Torre
    case 'A':
        return std::abs(fD - fO) == std::abs(cD - cO);  // Alfil
    case 'C': {
        int df = std::abs(fD - fO); int dc = std::abs(cD - cO);
        return (df == 2 && dc == 1) || (df == 1 && dc == 2);
    }  // Caballo
    case 'Q':
        return (fO == fD || cO == cD || std::abs(fD - fO) == std::abs(cD - cO));  // Reina
    case 'K':
        return std::abs(fD - fO) <= 1 && std::abs(cD - cO) <= 1;  // Rey
    }
    return false;
}

bool moverPieza(int fO, int cO, int fD, int cD) {
    if (!esMovimientoValido(fO, cO, fD, cD)) return false;

    char pieza = tablero[fO][cO];

    // PROMOCIÓN PEÓN (simple)
    if (pieza == PEON_BLANCO && fD == 0) pieza = REINA_BLANCA;
    if (pieza == PEON_NEGRO && fD == 7) pieza = REINA_NEGRA;

    // Mover
    tablero[fD][cD] = pieza;
    tablero[fO][cO] = VACIO;
    return true;
}

int main() {
    system("cls");
    std::cout << "===================" << std::endl;
    std::cout << "   JUEGO DE AJEDREZ" << std::endl;
    std::cout << "===================" << std::endl;

    inicializarTablero();

    while (true) {
        mostrarTablero();

        std::cout << "Turno: " << (turnoBlancas ? "BLANCAS" : "NEGRAS") << std::endl;
        std::cout << "Movimiento (fila col origen fila col destino): ";

        int fO, cO, fD, cD;
        if (!(std::cin >> fO >> cO >> fD >> cD)) {
            std::cout << "Salida..." << std::endl;
            break;
        }

        // Convertir coordenadas (usuario 1-8 → array 0-7)
        int realFO = 8 - fO;
        int realFD = 8 - fD;
        int realCO = cO - 1;
        int realCD = cD - 1;

        if (moverPieza(realFO, realCO, realFD, realCD)) {
            turnoBlancas = !turnoBlancas;  // Cambiar turno
            std::cout << "¡MOVIMIENTO OK!" << std::endl;
        }
        else {
            std::cout << "¡MOVIMIENTO NO VÁLIDO!" << std::endl;
        }

        std::cout << "Presiona Enter...";
        std::cin.ignore();
        std::cin.get();
        system("cls");
    }

    return 0;
}
