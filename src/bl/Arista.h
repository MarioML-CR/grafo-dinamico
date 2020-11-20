//
// Created by Mario Martinez on 19/11/20.
//

#ifndef GRAFO_DINAMICO_ARISTA_H
#define GRAFO_DINAMICO_ARISTA_H
class Arista;
#include "Vertice.h"

class Arista {
public:
    Arista(int peso);

    virtual ~Arista();

    int getPeso() const;

    void setPeso(int peso);

    Arista *getSig() const;

    void setSig(Arista *sig);

    Vertice *getAdy() const;

    void setAdy(Vertice *ady);

private:
    int peso;
    Arista *sig;
    Vertice *ady;
};


#endif //GRAFO_DINAMICO_ARISTA_H
