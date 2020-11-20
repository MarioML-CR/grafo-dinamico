//
// Created by Mario Martinez on 19/11/20.
//

#ifndef GRAFO_DINAMICO_GESTOR_H
#define GRAFO_DINAMICO_GESTOR_H


#include "../bl/Grafo.h"

class Gestor {
public:
    Gestor();

    Grafo *getGrafo() const;

    void setGrafo(Grafo *grafo);

    void insertVertice(string nombre);

    void insertaArista(string salida, string llegada, int peso);

    void listaAdyacencia();

    void eliminarArista(string salida, string llegada);

    string eliminarVertice(string vertice);

    void anular();

    int tamanio();

    bool vacio() const;

    void recorridoAnchura(string pOrigen);
private:
    Grafo *grafo;
};


#endif //GRAFO_DINAMICO_GESTOR_H
