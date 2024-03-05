/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez
 * @date    05/03/2024
 * @brief   Framework para algoritmos de Divide y Vencerás     
*/



#include <iostream>
#include <vector>
#include <random>
#include <ctime>

#include "Framework/Divide_Y_Venceras.h"
#include "Framework/Mergesort.h"
#include "Framework/Quicksort.h"



// Función para generar un vector aleatorio de un tamaño específico
std::vector<int> generarVectorAleatorio() {
    std::vector<int> vectorAleatorio;
    std::mt19937 generador(std::time(0) + clock()); 
    std::uniform_int_distribution<int> tamanoDistribution(10, 15); 
    std::uniform_int_distribution<int> valorDistribution(1, 100);  
    int tamano = tamanoDistribution(generador);
    for (int i = 0; i < tamano; ++i) {
        vectorAleatorio.push_back(valorDistribution(generador));
    }
    return vectorAleatorio;
}



int main () {
  Divide_Y_Venceras* algoritmo;

  algoritmo = new Mergesort;
  std::vector<int> cadena = generarVectorAleatorio();
  int numeroDeLamadasMergesort = 0;
  std::vector<int> resultado = algoritmo->resolver(cadena, numeroDeLamadasMergesort);
  std::cout << "Algortimo con Mergesort" << std::endl;
	std::cout << algoritmo->recurrecia() << std::endl << "Cadena inicial: {";
  for (int i = 0; i < cadena.size() - 1; i++) {
    std::cout << cadena[i] << ", ";
  }
  std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
	std::cout << "Resultado: {";
  for (int i = 0; i < resultado.size() - 1; i++) {
    std::cout << resultado[i] << ", ";
	}
	std::cout << resultado[resultado.size() - 1] << "}" << std::endl;
  std::cout << "El nivel maximo del arbol del algoritmo es: " << algoritmo->nivelMaximoArbol(cadena, 1) << std::endl;
  std::cout << "Numero de llamadas al algoritmo: " << numeroDeLamadasMergesort << std::endl << std::endl;

  algoritmo = new Quicksort;
  cadena = generarVectorAleatorio();
  int numeroDeLamadasQuicksort = 0;
  resultado = algoritmo->resolver(cadena, numeroDeLamadasQuicksort);
  std::cout << "Algortimo con Quicksort" << std::endl;
	std::cout << algoritmo->recurrecia() << std::endl << "Cadena inicial: {";
  for (int i = 0; i < cadena.size() - 1; i++) {
    std::cout << cadena[i] << ", ";
  }
  std::cout << cadena[cadena.size() - 1] << "}" << std::endl;
	std::cout << "Resultado: {";
  for (int i = 0; i < resultado.size() - 1; i++) {
    std::cout << resultado[i] << ", ";
	}
	std::cout << resultado[resultado.size() - 1] << "}" << std::endl;
  std::cout << "El nivel maximo del arbol del algoritmo es: " << algoritmo->nivelMaximoArbol(cadena, 1) << std::endl;
  std::cout << "Numero de llamadas al algoritmo: " << numeroDeLamadasQuicksort << std::endl;

  return 0;
}