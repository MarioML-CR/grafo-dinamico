//
// Created by Mario Martinez on 19/11/20.
//

#ifndef GRAFO_DINAMICO_ARISTA_H
#define GRAFO_DINAMICO_ARISTA_H
class Arista;
#include "Vertice.h"
#include <string>
using namespace std;

class Arista {
public:

    Arista(int peso, const string &nombre, Vertice *ady, Arista *sig = nullptr);

    virtual ~Arista();

    int getPeso() const;

    void setPeso(int peso);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Arista *getSig() const;

    void setSig(Arista *sig);

    Vertice *getAdy() const;

    void setAdy(Vertice *ady);

private:
    int peso;
    string nombre;
    Vertice *ady;
    Arista *sig;
};


#endif //GRAFO_DINAMICO_ARISTA_H
