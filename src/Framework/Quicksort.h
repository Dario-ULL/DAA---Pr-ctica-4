/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/


#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "Divide_Y_Venceras.h"

class Quicksort : public Divide_Y_Venceras {
	std::vector<int> resolverPequeño (std::vector<int> entrada) const;
	bool tamaño (std::vector<int> entrada) const;
	std::vector<std::vector<int>> dividir (std::vector<int> entrada) const;
	std::vector<int> combinar (std::vector<int> solucion1, std::vector<int> solucion2) const;

	std::string numeroSubProblemas () const;
	std::string factorDeReduccion () const;
	std::string tiempoDeCombinacion () const;
};



std::vector<int> 
Quicksort::resolverPequeño (std::vector<int> entrada) const {
	return entrada;
}



bool 
Quicksort::tamaño (std::vector<int> entrada) const {
 	return entrada.size() <= 1;	
}



std::vector<std::vector<int>> 
Quicksort::dividir (std::vector<int> entrada) const {
	std::vector<std::vector<int>> particion;
	particion.resize(2);
  int pivote = entrada.back();
	particion[1].push_back(pivote);
  for (int i = 0; i < entrada.size() - 1; i++) {
    if (entrada[i] <= pivote) {
			particion[0].push_back(entrada[i]);
    } else {
			particion[1].push_back(entrada[i]);
		}
  }
	return particion;
}



std::vector<int> 
Quicksort::combinar (std::vector<int> solucion1, std::vector<int> solucion2) const {
  std::vector<int> combinacion = solucion1;
  combinacion.insert(combinacion.end(), solucion2.begin(), solucion2.end());
  return combinacion;
}



std::string 
Quicksort::numeroSubProblemas () const {
	return "T(k)";
}



std::string  
Quicksort::factorDeReduccion () const {
	return "n - k - 1";
}



std::string 
Quicksort::tiempoDeCombinacion () const {
	return "n";
}



#endif