//
// Created by Mario Martinez on 19/11/20.
//

#ifndef GRAFO_DINAMICO_GRAFO_H
#define GRAFO_DINAMICO_GRAFO_H

//class Arista;
#include "Vertice.h"
#include <queue> // para la cola
#include <list> // para la lista
#include <stack> // para la pila

class Grafo {
public:
    Grafo(Vertice *h = nullptr);

    virtual ~Grafo();

    Vertice *getHead() const;

    void setHead(Vertice *head);

    bool vacio() const;

    int numVertices() const;

    Vertice *getVertice(string nombre);

    void insertaArista(string salida, string llegada, int peso);

    void insertVertice(int valor, string & nombre);

    void listaAdyacencia();

    void eliminarArista(string salida, string llegada);

    bool eliminarVertice(string pEliminar);

    void elminarGrafo();

    void recorridoAnchura(string pOrigen);

    void recorridoProfundidad(string pOrigen);

    void primeroAnchura(string pOrigen, string pDestino);

    void primeroProfundidad(string pOrigen, string pDestino);

    void dijkstra(string pOrigen, string pDestino);
private:
    Vertice *head;

    void eliminarArista(Vertice * origen, Vertice * destino);

    bool eliminarVertice(Vertice * vert);

    void recorridoAnchura(Vertice *origen);

    void recorridoProfundidad(Vertice *origen);

    void primeroAnchura(Vertice * origen, Vertice * destino);

    void primeroProfundidad(Vertice * origen, Vertice * destino);

    void dijkstra(Vertice * origen, Vertice * destino);

    static bool comparacion(pair<Vertice*, int> a, pair<Vertice*, int> b);
};


#endif //GRAFO_DINAMICO_GRAFO_H
