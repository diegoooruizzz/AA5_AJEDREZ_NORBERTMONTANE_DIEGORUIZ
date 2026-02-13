#include <iostream>
#include <fstream>
#include <string>

//ROTOR1
std::string r1 = "QDLZAMWRFHSJXKTEYBUNOCGIPV";
char notchR1 = 'A';

//ROTOR2
std::string r2 = "MZQJATKBRWLSYFONHEDXUIGPVC";
char notchR2 = 'B';

//ROTOR3
std::string r3 = "ACFURPZLJYHEDMOKVNXIBWTSQG";
char notchR3 = 'C';


int main() {
	std::string mensajeParaCifrar;

	std::cout << "Dame un mensaje para cifrar: ";
	std::getline(std::cin, mensajeParaCifrar);
	
	//Quitar puntos, comas y simbolos especiales.
	std::string simboloEsp = ":;',.*@#?¿!¡ñç";
	for (int i = 0; i < mensajeParaCifrar.length(); i++)//por cada letra...
	{
		for (int j = 0; j < simboloEsp.length(); j++)//y por cada simbolo especial
		{
			if (mensajeParaCifrar[i] == simboloEsp[j]) { //comparo si la letra es un simbolo especial
				mensajeParaCifrar.erase(i,1);
				i--; 
			}
		}
	}
	std::cout << "[INFO] Quitar puntos, comas y simbolos especiales: " << mensajeParaCifrar;
	//Quitar acentos

	//Todo en mayusculas 

	//Separar en grupos de 5
	return 0;
}