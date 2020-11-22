//
// Created by Mario Martinez on 19/11/20.
//

#ifndef GRAFO_DINAMICO_VALIDAR_H
#define GRAFO_DINAMICO_VALIDAR_H
#include <iostream>
using namespace std;

class Validar {
public:
    int ingresarInt(string);

    int nPrimoMenorQue(int); // retorna el número primo menor al valor pasado por argumento

    bool esPrimo(int); // Analiza si un número es primo

    int stringASCII(string &);
};

#endif //GRAFO_DINAMICO_VALIDAR_H
