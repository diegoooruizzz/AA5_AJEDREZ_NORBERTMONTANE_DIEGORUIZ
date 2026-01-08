#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "funciones.h"
#include "define.h"


int inputUsuario;
int primeraOpcion = 1;
int segundaOpcion = 2;
int terceraOpcion = 3;

char tablero1[TABLERO_VERTICAL_FACIL][TABLERO_HORIZONTAL_FACIL];
char tablero2[TABLERO_VERTICAL_NORMAL][TABLERO_HORIZONTAL_NORMAL];
char tablero3[TABLERO_VERTICAL_DIFICIL][TABLERO_HORIZONTAL_DIFICIL];

void inicializarTablero1() { //inicializamos tablero 
	for (int i = 0; i < TABLERO_VERTICAL_FACIL; i++)
	{
		for (int j = 0; j < TABLERO_HORIZONTAL_FACIL; j++)
		{
			tablero1[i][j] = '~';
		}
	}
}

void mostrarTablero1() { //mostramos tablero de 3x3
	for (int i = 0; i < TABLERO_VERTICAL_FACIL; i++)
	{

		for (int j = 0; j < TABLERO_HORIZONTAL_FACIL; j++)
		{
			std::cout << tablero1[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void inicializarTablero2() { //inicializamos tablero 
	for (int i = 0; i < TABLERO_VERTICAL_NORMAL; i++)
	{
		for (int j = 0; j < TABLERO_HORIZONTAL_NORMAL; j++)
		{
			tablero2[i][j] = '~';
		}
	}
}

void mostrarTablero2() { //mostramos tablero 4x4
	for (int i = 0; i < TABLERO_VERTICAL_NORMAL; i++)
	{

		for (int j = 0; j < TABLERO_HORIZONTAL_NORMAL; j++)
		{
			std::cout << tablero2[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void inicializarTablero3() { //inicializamos tablero
	for (int i = 0; i < TABLERO_VERTICAL_DIFICIL; i++)
	{
		for (int j = 0; j < TABLERO_HORIZONTAL_DIFICIL; j++)
		{
			tablero3[i][j] = '~';
		}
	}
}

void mostrarTablero3() { //mostramos tablero 5x5
	for (int i = 0; i < TABLERO_VERTICAL_DIFICIL; i++)
	{

		for (int j = 0; j < TABLERO_HORIZONTAL_DIFICIL; j++)
		{
			std::cout << tablero3[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main() {
	std::cout << "============================================" << std::endl;
	std::cout << "BIENVENIDO A TU JUEGO" << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << "Con que dificultad quieres jugar ? FACIL, NORMAL O DIFICIL siendo FACIL = 1, NORMAL = 2; DIFICL = 3: " << std::endl;
	std::cin >> inputUsuario;
	
	if (inputUsuario == primeraOpcion)
	{
			inicializarTablero1(); 	
			mostrarTablero1(); 
			
	}
	if (inputUsuario == segundaOpcion)
	{
		inicializarTablero2();
		mostrarTablero2();
	}
	
	if (inputUsuario == terceraOpcion)
	{
		inicializarTablero3();
		mostrarTablero3();
	}

	
	return 0;
}