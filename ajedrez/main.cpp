#include <iostream>
#include "define.h"
#include "main.h"
#include <cstdlib>

//definimos el tablero
char tablero[TABLERO_FILAS][TABLERO_COLUMNAS];


void inicializarTablero() {
    // 1. Llenar todo de vacio
    for (int i = 0; i < TABLERO_FILAS; i++) {
        for (int j = 0; j < TABLERO_COLUMNAS; j++) {
            tablero[i][j] = VACIO;
        }
    }

    // Orden: t h b k q b h t
    tablero[0][0] = TORRE_NEGRA;
    tablero[0][1] = CABALLO_NEGRO;
    tablero[0][2] = ALFIL_NEGRO;
    tablero[0][3] = REY_NEGRO;
    tablero[0][4] = REINA_NEGRA;
    tablero[0][5] = ALFIL_NEGRO;
    tablero[0][6] = CABALLO_NEGRO;
    tablero[0][7] = TORRE_NEGRA;

    // Peones Negros fila 1
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        tablero[1][j] = PEON_NEGRO;
    }

    // Orden: T H B Q K B H T
    tablero[7][0] = TORRE_BLANCA;
    tablero[7][1] = CABALLO_BLANCO;
    tablero[7][2] = ALFIL_BLANCO;
    tablero[7][3] = REINA_BLANCA;
    tablero[7][4] = REY_BLANCO;
    tablero[7][5] = ALFIL_BLANCO;
    tablero[7][6] = CABALLO_BLANCO;
    tablero[7][7] = TORRE_BLANCA;

    // Peones Blancos fila 6
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        tablero[6][j] = PEON_BLANCO;
    }
}

void mostrarTablero() {
    //columnas
    std::cout << "   "; //espacio para poner el numero de fila
    for (int j = 0; j < TABLERO_COLUMNAS; j++) {
        std::cout << j + 1 << " ";
    }
    std::cout << std::endl;

    //filas
    for (int i = 0; i < TABLERO_FILAS; i++) {
        //numero de fila a la izquierda del 8 al 1
        std::cout << 8 - i << "  ";

        //piezas
        for (int j = 0; j < TABLERO_COLUMNAS; j++) {
            char pieza = tablero[i][j];
            std::cout << pieza << " ";
        }
        std::cout << std::endl;
    }
}

bool moverPieza(int filaOrigen, int colOrigen, int filaDestino, int colDestino) {
    //verificamos si hay pieza
    if (tablero[filaOrigen][colOrigen] == VACIO) {
        std::cout << "Error: No hay pieza en esta posicion." << std::endl;
        return false;
    }

    //con esto movemos las piezas 
    tablero[filaDestino][colDestino] = tablero[filaOrigen][colOrigen];
    tablero[filaOrigen][colOrigen] = VACIO;

    return true;
}

bool esMovimientoValido(int fO, int cO, int fD, int cD) {//fO = fila de origen, cO = columna de origen, fD = fila de destino, cD = columna de destino
    char pieza = tablero[fO][cO];
    int difFila = abs(fD - fO);
    int difCol = abs(cD - cO);

    //esto lo que hace es que no vaya al mismo sitio
    if (fO == fD && cO == cD) return false;

    //movimientos de cada pieza
    switch (toupper(pieza)) { // toupper para no repetir lógica entre blancas y negras
    case 'P': // PEÓN (Lógica simplificada: solo 1 paso adelante)
        if (difCol == 0 && difFila == 1) return true;
        break;

    case 'T': //torre solo recto
        if (fO == fD || cO == cD) return true;
        break;

    case 'A': //alfil solo en diagonal
        if (difFila == difCol) return true;
        break;

    case 'C': //caballo en l 
        if ((difFila == 2 && difCol == 1) || (difFila == 1 && difCol == 2)) return true;
        break;

    case 'Q': //reina solo puede ir recta y en diagonal
        if (fO == fD || cO == cD || difFila == difCol) return true;
        break;

    case 'K': //rey 1 paso a cualquier lado pero 1
        if (difFila <= 1 && difCol <= 1) return true;
        break;
    }

    return false; //el movimiento no es valido
}

int main() {

    system("cls");
    std::cout << "---------------------------" << std::endl;
    std::cout << "  JUEGO AJEDREZ" << std::endl;
    std::cout << "---------------------------" << std::endl;

    inicializarTablero();

    bool turnoBlancas = true; // Empiezan las blancas
    int fO, cO, fD, cD;

    while (true) {
        mostrarTablero();

        if (turnoBlancas)
        {
            std::cout << "Turno: BLANCAS" << std::endl;
        }
        else
        {
            std::cout << "Turno: NEGRAS" << std::endl;
        }
        std::cout << "Introduce movimiento (ejemplo= 2 1 3 1): ";
        if (!(std::cin >> fO >> cO >> fD >> cD)) {
            break; // Salir si el usuario mete algo que no sea un numero
        }

        //ajuste de las coordenadas para que cuando nosotros pidamos una coordenada la array haga su efecto y borre -1 para que a nosotros nos de 0
        int realFO = 1 - fO;
        int realFD = 1 - fD;
        int realCO = cO - 8;
        int realCD = cD - 8;


        if (moverPieza(realFO, realCO, realFD, realCD)) //si el movimiento esta bien se cambia el turno 
        {
            turnoBlancas = !turnoBlancas;
        }
        else {
            std::cout << "¡Movimiento invalido!" << std::endl;
            std::cin.ignore();
            std::cin.get();
        }
    }

    return 0;

    std::cin >> fO >> cO >> fD >> cD;

    moverPieza(fO, cO, fD, cD);
    mostrarTablero();


    return 0;
};