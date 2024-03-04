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
	std::vector<int> resolver (std::vector<int> entrada);

	virtual std::string numeroSubProblemas () const = 0;
	virtual std::string factorDeReduccion () const = 0;
	virtual std::string tiempoDeCombinacion () const = 0;
	std::string recurrecia ();
};



std::vector<int>
Divide_Y_Venceras::resolver (std::vector<int> entrada) {
  if (tamaño(entrada)) {
    return resolverPequeño(entrada);
  } else {
    std::vector<std::vector<int>> division = dividir(entrada);
    std::vector<int> solucion1 = resolver(division[0]);
    std::vector<int> solucion2 = resolver(division[1]);
    std::vector<int> solucion = combinar(solucion1, solucion2);
    return solucion;
  }	
}


std::string
Divide_Y_Venceras::recurrecia () {
	std::string resultado = "T(n) <= ";
	resultado += numeroSubProblemas() + "T(";
	resultado += factorDeReduccion() + ") + ";
	resultado += tiempoDeCombinacion();
	return resultado;
}


#endif