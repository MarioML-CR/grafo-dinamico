//
// Created by Mario Martinez on 19/11/20.
//

#ifndef GRAFO_DINAMICO_GRAFO_H
#define GRAFO_DINAMICO_GRAFO_H

//class Arista;
#include "Vertice.h"
#include <queue>
#include <list>

class Grafo {
public:
    Grafo(Vertice *h = nullptr);

    virtual ~Grafo();

    Vertice *getH() const;

    void setH(Vertice *h);

    bool vacio() const;

    int tamanio() const;

    Vertice *getVertice(string nombre);

    void insertaArista(string salida, string llegada, int peso);

    void insertVertice(string nombre);

    void listaAdyacencia();

    void eliminarArista(string, string);

    bool eliminarVertice(string);

    void anular();

    void recorridoAnchura(string pOrigen);
private:
    Vertice *h;

    void eliminarArista(Vertice *, Vertice *);

    bool eliminarVertice(Vertice *);

    void recorridoAnchura(Vertice *origen);

};


#endif //GRAFO_DINAMICO_GRAFO_H
