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
    Vertice(const string &nombre);

    virtual ~Vertice();

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Vertice *getSig() const;

    void setSig(Vertice *sig);

    Arista *getAdy() const;

    void setAdy(Arista *ady);


private:
    string nombre;
    Vertice *sig;
    Arista *ady;
};


#endif //GRAFO_DINAMICO_VERTICE_H
