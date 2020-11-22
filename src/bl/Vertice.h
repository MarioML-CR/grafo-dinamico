//
// Created by Mario Martinez on 19/11/20.
//

#ifndef GRAFO_DINAMICO_VERTICE_H
#define GRAFO_DINAMICO_VERTICE_H

class Vertice;
#include "Arista.h"

#include <string>


using namespace std;



class Vertice {
public:
//    Vertice(const string &nombre);

    Vertice(int valor, const string &nombre, Vertice *sig = nullptr, Arista *ady = nullptr);

    virtual ~Vertice();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Vertice *getNext() const;

    void setNext(Vertice *next);

    Arista *getAdy() const;

    void setAdy(Arista *ady);

    int getValor() const;

    void setValor(int valor);

private:
    int valor; // para ordenar lo vértices en forma ascendente
    string nombre;
    Vertice *next;
    Arista *ady;
};


#endif //GRAFO_DINAMICO_VERTICE_H
