# DAA - Práctica 4

## Objetivos de la práctica
Los siguientes objetivos se consideran condición necesaria pero no suficiente para aprobar la práctica:

Crear un Framework que utilice el patrón “Template” para la implementación de algoritmos de Divide y Vencerás binarios.
Utilizar el paradigma de Programación Orientada a Objetos, así como los lenguajes de programación C++, C# o Java.
Implementar haciendo uso del Framework creado los algoritmos de MergeSort y QuickSort


## Requisitos evaluables de la práctica
Los siguientes requisitos se evaluarán de cara a la entrega de la práctica:

1- Todo el código deberá estar adecuadamente comentado y desarrollado atendiendo al paradigma de Programación Orientada a Objetos.

2-  El Framework tiene que estar bien implementado de acuerdo al patrón “Template”.

3-  Los algoritmos MergeSort y QuickSort deben hacer un buen uso de la plantilla. NO deben poder ejecutarse sin hacer uso de la plantilla.

4-  Debe crearse un generador de instancias que permita la creación de vectores de enteros desordenados de diferentes tamaños.

5-  Debe crearse un fichero principal (main) que realice los siguientes pasos:
    a.  Genere un conjunto de instancias aleatorias de diferentes tamaños.
    b.  Para cada instancia, ejecute los algoritmos MergeSort y QuickSort.
    c.  Muestre por pantalla (y opcionalmente por fichero) una tabla con la comparación de tiempos de ejecución de los algoritmos para diferentes tamaños de instancia.

6-  El Framework debe poseer mínimo 2 métodos:
    a.  Un método que permita la ejecución del algoritmo y devuelva su solución.
    b.  Un método que devuelva una cadena de caracteres que represente la recurrencia del algoritmo en cuestión. Ésta debe ser de la forma T(n) <= aT(b) + c, donde a, b y c son devueltos por el algoritmo específico.

7-  Tanto las soluciones como las instancias deben estar preparadas para la utilización de otros algoritmos además de los solicitados.


## La organización del directorio del proyecto es la siguiente:

```
└── src
    ├── Framework
    │       ├── Divide_Y_Venceras.h
    │       ├── Mergesort.h
    │       └── Quicksort.h
    └── main.cc
```