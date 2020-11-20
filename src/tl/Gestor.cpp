//
// Created by Mario Martinez on 19/11/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    grafo = new Grafo();
}

Grafo *Gestor::getGrafo() const {
    return grafo;
}

void Gestor::setGrafo(Grafo *grafo) {
    Gestor::grafo = grafo;
}

void Gestor::insertVertice(string nombre) {
    getGrafo()->insertVertice(nombre);
}

void Gestor::insertaArista(string salida, string llegada, int peso) {
    getGrafo()->insertaArista(salida, llegada, peso);
}

void Gestor::listaAdyacencia() {
    getGrafo()->listaAdyacencia();
}

void Gestor::eliminarArista(string salida, string llegada) {
    getGrafo()->eliminarArista(salida, llegada);
}

void Gestor::anular() {
    getGrafo()->anular();
}

int Gestor::tamanio() {
    return getGrafo()->tamanio();
}

bool Gestor::vacio() const {
    return getGrafo()->vacio();
}

string Gestor::eliminarVertice(string vertice) {
    if (getGrafo()->eliminarVertice(vertice)) {
        return "El vértice fue eliminado\n";
    } else {
        return "El vértice que ingresó no existe\n";
    }
}

void Gestor::recorridoAnchura(string pOrigen) {
    getGrafo()->recorridoAnchura(pOrigen);
}

void Gestor::recorridoProfundidad(string pOrigen) {
    getGrafo()->recorridoProfundidad(pOrigen);
}

void Gestor::primeroAnchura(string pOrigen, string pDestino) {
    getGrafo()->primeroAnchura(pOrigen, pDestino);
}

void Gestor::primeroProfundidad(string pOrigen, string pDestino) {
    getGrafo()->primeroProfundidad(pOrigen, pDestino);
}


