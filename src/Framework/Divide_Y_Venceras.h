/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef DIVIDE_Y_VENCERAS_H_
#define DIVIDE_Y_VENCERAS_H_

#include <iostream>
#include <vector>
#include <string>

class Divide_Y_Venceras {
 public:
	virtual std::vector<int> resolverPequeño (std::vector<int> entrada) const = 0;
	virtual bool tamaño (std::vector<int> entrada) const = 0;
	virtual std::vector<std::vector<int>> dividir (std::vector<int> entrada) const = 0;
	virtual std::vector<int> combinar (std::vector<int> solucion1, std::vector<int> solucion2) const = 0;
	std::vector<int> resolver (std::vector<int> entrada, int& numeroTotalDeLlamadas);

	virtual std::string numeroSubProblemas () const = 0;
	virtual std::string factorDeReduccion () const = 0;
	virtual std::string tiempoDeCombinacion () const = 0;
	std::string recurrecia ();

	int nivelMaximoArbol (std::vector<int> entrada, int nivelArbol);
};


/**
 * Resuelve de forma recursiva un algoritmo de Divide y Venceras
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @param {int} numeroTotalDeLlamadas  -  Numero de iteraciones del programa
 * @return {std::vector<int>}
*/
std::vector<int>
Divide_Y_Venceras::resolver (std::vector<int> entrada, int& numeroTotalDeLlamadas) {
	numeroTotalDeLlamadas++;
  if (tamaño(entrada)) {
    return resolverPequeño(entrada);
  } else {
    std::vector<std::vector<int>> division = dividir(entrada);
    std::vector<int> solucion1 = resolver(division[0], numeroTotalDeLlamadas);
    std::vector<int> solucion2 = resolver(division[1], numeroTotalDeLlamadas);
    std::vector<int> solucion = combinar(solucion1, solucion2);
    return solucion;
  }	
}



/**
 * Devuelve la recurrencia de un algoritmo de Divivde y Venceras
 * @return {std::string}
*/
std::string
Divide_Y_Venceras::recurrecia () {
	std::string resultado = "T(n) <= ";
	resultado += numeroSubProblemas() + "T(";
	resultado += factorDeReduccion() + ") + ";
	resultado += tiempoDeCombinacion();
	return resultado;
}



/**
 * Devuelve el nivel maximo de un arbol de un algoritmo de Divide y Venceras
 * @param {std::vector<int>} entrada  -  Cadena de numeros
 * @return {int}
*/
int 
Divide_Y_Venceras::nivelMaximoArbol (std::vector<int> entrada, int nivelArbol) {
	if (tamaño(entrada)) {
    return nivelArbol;
  } else {
		std::vector<std::vector<int>> division = dividir(entrada);
		int nivelArbol1 = nivelMaximoArbol(division[0], nivelArbol++);
		int nivelArbol2 = nivelMaximoArbol(division[1], nivelArbol++);
		if (nivelArbol1 < nivelArbol2) {
			return nivelArbol2;
		} else {
			return nivelArbol1;
		}		
	}
}


#endif