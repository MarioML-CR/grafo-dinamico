//
// Created by Mario Martinez on 19/11/20.
//

#include <iostream>
#include "Grafo.h"



Grafo::Grafo(Vertice *h) : h(h) {
    setH(nullptr);
}

Grafo::~Grafo() {

}

Vertice *Grafo::getH() const {
    return h;
}

void Grafo::setH(Vertice *h) {
    Grafo::h = h;
}

bool Grafo::vacio() const {
    return getH() == nullptr;
}

int Grafo::tamanio() const {
    int cont = 0;
    Vertice * aux = getH();
    while (aux != nullptr){
        aux = aux->getSig();
        cont ++;
    }
    return cont;
}

Vertice *Grafo::getVertice(string nombre) {
    Vertice * aux = getH();
    while (aux != nullptr){
        if (aux->getNombre().compare(nombre) == 0) {
            return aux;
        }
        aux = aux->getSig();
    }
    return aux;
}

void Grafo::insertaArista(string salida, string llegada, int peso) {
    Vertice *origen = getVertice(salida);
    Vertice *destino = getVertice(llegada);
//    Vertice *origen = new Vertice(salida);
//    Vertice *destino = new Vertice(llegada);
    Arista *nueva = new  Arista(peso);
    Arista *aux = origen->getAdy();
    if (aux == nullptr){
        origen->setAdy(nueva);
        nueva->setAdy(destino);
    } else {
        /** recorre las aristas hasta llegar a la última para insertar la nueva arista y
         * conectarla con el vértice destino.
         */
        while (aux->getSig() != nullptr){
            aux = aux->getSig();
        }
        aux->setSig(nueva);
        nueva->setAdy(destino);
    }
}

void Grafo::insertVertice(string nombre) {
    Vertice *nuevo = new Vertice(nombre);
    if (vacio()) {
        setH(nuevo);
    } else {
        Vertice *aux = getH();
        while (aux->getSig() != nullptr){
            aux = aux->getSig();
        }
        aux->setSig(nuevo);
    }
}

void Grafo::listaAdyacencia() {
    Vertice *vertAux = getH();
    Arista * arisAux;
    while (vertAux != nullptr){
        cout << vertAux->getNombre() << "->";
        arisAux = vertAux->getAdy();
        while (arisAux != nullptr){
            cout << arisAux->getAdy()->getNombre() << "->";
            arisAux = arisAux->getSig();
        }
        vertAux = vertAux->getSig();
        cout << endl;
    }
}

void Grafo::eliminarArista(string salida, string llegada) {
    // TODO TIENE ERROR.
    Vertice *origen = getVertice(salida);
    Vertice *destino = getVertice(llegada);
    eliminarArista(origen, destino);
}

void Grafo::eliminarArista(Vertice * origen, Vertice * destino) {
    if (origen == nullptr || destino == nullptr){
        cout << "El origen o destino no existen\n";
    } else {
        int band = 0;
        Arista *actual, *anterior;
        actual = origen->getAdy();
        if (actual == nullptr){ // no existe arista
            cout << "El vértice origen no tiene aristas" << endl;
        } else if(actual->getAdy() == destino){ // la primera arista
            origen->setAdy(actual->getSig());
            delete actual;
        } else { // cualquier otra arista
            while (actual->getAdy() != nullptr){
                if (actual->getAdy() == destino){
                    band = 1;
                    anterior->setSig(actual->getSig());
                    delete actual;
                    break;
                }
                anterior = actual;
                actual = actual->getSig();
            }
            if (band == 0){
                cout << "Esos dos vértices no están conectados" << endl;
            }

        }
    }
}
void Grafo::anular() {
    Vertice *aux;
    while (getH() != nullptr){
        aux = getH();
        setH(getH()->getSig());
        delete aux;
    }
}

bool Grafo::eliminarVertice(string pEliminar) {
    Vertice *vert = getVertice(pEliminar);
    return eliminarVertice(vert);
}

bool Grafo::eliminarVertice(Vertice *vert) {
    if (vert == nullptr){
        return false;
//        cout << "No existe el vertice\n";
    } else {
        Vertice *actual, *anterior;
        Arista *aux;
        actual = getH();
        while (actual != nullptr){
            aux = actual->getAdy();
            while (aux != nullptr){
                if (aux->getAdy() == vert){
                    eliminarArista(actual, aux->getAdy());
                    break;
                }
                aux = aux->getSig();
            }
            actual = actual->getSig();
        }
        actual =getH();
        if (getH() == vert){
            setH(getH()->getSig());
            delete actual;
        } else {
            while (actual != vert){
                anterior = actual;
                actual = actual->getSig();
            }
            anterior->setSig(actual->getSig());
            delete actual;
        }
        return true;
    }
}

void Grafo::recorridoAnchura(string pOrigen) {
    Vertice *origen = getVertice(pOrigen);
    recorridoAnchura(origen);
}

void Grafo::recorridoAnchura(Vertice *origen) {
    if (origen == nullptr){
        cout << "No exite el vértice\n";
    } else {
        int band, band2;
        Vertice *actual;
        queue<Vertice*> cola;
        list<Vertice*> lista;
        list<Vertice*>::iterator i;
        cola.push(origen); // se coloca el vértice origen en una cola (el que pasan como parámetro
        while (!cola.empty()){ // mientras la cola no esté vacía
            band = 0;
            actual = cola.front();
            cola.pop(); // desencolamos un vértice, será el vértice actual
            for (i = lista.begin(); i != lista.end(); i++) {
                if (*i == actual){
                    band = 1;
                }
            }
            if (band == 0) { // si el vértice actual no ha sido visitado
                cout << actual->getNombre() << ", "; // procesar el vértice actual
                lista.push_back(actual); // colocar el vértice en la lista de visitados
                Arista * aux = actual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++) { // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // encolar el vértice
                        cola.push(aux->getAdy());
                    }
                    aux = aux->getSig();
                }
            }
        }
    }
}

void Grafo::recorridoProfundidad(string pOrigen) {
    Vertice *origen = getVertice(pOrigen);
    recorridoProfundidad(origen);
}

void Grafo::recorridoProfundidad(Vertice *origen) {
    if (origen == nullptr){
        cout << "No exite el vértice\n";
    } else {
        int band, band2;
        Vertice *actual;
        stack<Vertice*> pila;
        list<Vertice*> lista;
        list<Vertice*>::iterator i; // iterador para la lista
        pila.push(origen); // se coloca el vértice origen en una pila
        while (!pila.empty()){ // mientras la pila no esté vacía:
            band = 0;
            actual = pila.top();
            pila.pop(); // desepilar el vértice, será el vértice actual
            for (i = lista.begin(); i != lista.end(); i++) { // si el vertice actual no ha sido visitado o está en la lista
                if (*i == actual){
                    band = 1;
                }
            }
            if (band == 0){ // si el vertice actual no ha sido visitado:
                cout << actual->getNombre() << ", "; // se "procesa" el vértice actual
                lista.push_back(actual); // se coloca el vértice actual en la lista de visitados
                Arista *aux = actual->getAdy(); // se va a ubicar en la primera arista del vértice actual
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++) {
                        if (*i == aux->getAdy()) {
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado.
                        pila.push(aux->getAdy()); // apilar el vértice
                    }
                    aux = aux->getSig();
                }
            }
        }
    }
}

void Grafo::primeroAnchura(string pOrigen, string pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    primeroAnchura(origen, destino);
}

void Grafo::primeroAnchura(Vertice *origen, Vertice *destino) {
    if (origen == nullptr || destino == nullptr){
        cout << "El origen o destino no existen\n";
    } else {
        // colocar el vértice origen en una cola
        // inicializar una pila que almacene parejas de datos origen-destino
        // mientras la cola no esté vacía
        // desencolar un vértice, será el vértice actual
        //si el vértice actual no ha sido visitado:
        // si el vértice
    }
}




