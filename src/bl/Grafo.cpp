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
        int band, band2, band3 = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, Vertice*> VerticeVertice; // pila de parejas de vértices
        queue<Vertice*> cola;
        stack<VerticeVertice> pila; // inicializar una pila que almacene parejas de datos origen-destino
        list<Vertice*> lista;
        list<Vertice*>::iterator i;
        cola.push(origen); // colocar el vértice origen en una cola
        while (!cola.empty()){ // mientras la cola no esté vacía
            band = 0;
            verticeActual = cola.front();
            cola.pop(); // desencolar un vértice, será el vértice actual
            for (i = lista.begin(); i != lista.end(); i++) {
                if (verticeActual == *i) {
                    band =1;
                }
            }
            if (band == 0){ //si el vértice actual no ha sido visitado:
                // mostrar la ruta encontrada
                if (verticeActual == destino){ // si el vértice actual es igual al vértice destino:
                    band3 = 1;
                    destinoActual = destino; // el vértice destino se convierte en destino actual
                    while (!pila.empty()){ // mientras la pila no esté vacía
                        cout << destinoActual->getNombre() << "<-"; // imprimir el destino actual; al revés porque en la pila se saca al revés
                        while (!pila.empty() && pila.top().second != destinoActual){ // mientras la pila no esté vacía y el vértice destino en el tope de la pila sea distinto del destino actual
                            pila.pop(); // desapilar
                        }
                        if (!pila.empty()){ // si la pila no está vacía
                            destinoActual = pila.top().first; // el vértice origen en el tope de la pila se convierte en el destino actual
                        }
                    }
//                    break;  // terminar
                }
                lista.push_back(verticeActual); // colocar el vértice actual en la lista de visitados
                aux = verticeActual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++){
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado
                        cola.push(aux->getAdy());
                        pila.push(VerticeVertice(verticeActual, aux->getAdy())); // apilar la pareja: vértice actual y vértice destino
                    }
                    aux = aux->getSig(); // encolar el vértice
                }
            }
        }
        if (band3 == 0){ // si la cola se vació sin encontrar el destino
            // no existe una ruta entre esos vértices
            cout << "No hay ruta entre esos dos vértices\n";
        }
    }
}

void Grafo::primeroProfundidad(string pOrigen, string pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    primeroProfundidad(origen, destino);
}

/*
 * Ruta de grafos
    se recibe una pila con parejas de vértices origen-destino, y se recibe el vértice destino
    el vértice destino se convierte en destino actual
    mientras la pila no esté vacía
    imprimir el destino actual
    mientras la pila no esté vacía y el vértice destino en el tope de la pila sea distinto del destino actual
    desapilar
    si la pila no está vacía
    el vértice origen en el tope de la pila se convierte en el destino actual
 */

/*
 * Primero en profundidad
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/*
 * se recibe una pila con parejas de vértices origen-destino, y se recibe el vértice destino
 *
 *
 *
 *
 *
 *
 *
 */

void Grafo::primeroProfundidad(Vertice *origen, Vertice *destino) {
    if (origen == nullptr || destino == nullptr){
        cout << "El origen o destino no existen\n";
    } else {
        int band, band2, band3 = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, Vertice*> parVertices;
        stack<Vertice*> pila;
        list<Vertice*> lista;
        stack<parVertices> pilaPar; // inicializar una pila que almacene parejas de datos origen-destino
        list<Vertice*>::iterator i; // se declara un iterador para la lista
        pila.push(origen); // colocar el vértice origen en una pila
        while (!pila.empty()){ // mientras la pila no esté vacía
            band = 0;
            verticeActual = pila.top(); // almacenamos el tope de la fila
            pila.pop(); // desapilar un vértice, seá el vértice actual
            for (i = lista.begin(); i != lista.end(); i++){
                if (verticeActual == *i){
                    band = 1;
                }
            }
            if (band == 0){ // si el vértice actual no ha sido visitado (no encontró ese vértice en la lista de visitados
                if (verticeActual == destino){ // si el vértice actual es igual al vértice destino
                    band3 = 1;
                    // mostrar la ruta encontrada
                    destinoActual = destino; // el vértice destino se convierte en destino actual
                    while (!pilaPar.empty()){ // mientras la pila no esté vacía
                        cout << destinoActual->getNombre() << "<-"; // imprimir el destino actual
                        while (!pilaPar.empty() && pilaPar.top().second != destinoActual){ // mientras la pila no esté vacía y el vértice destino en el tipo de la pila sea distinto del destino actual
                            pilaPar.pop(); // desapilar
                        }
                        if (!pilaPar.empty()){ // si la pila no está vacía
                            destinoActual = pilaPar.top().first; // el vértice origen en el tope de la pila se convierte en el destino actual
                        }
                    }
                    break; // terminar
                }
                lista.push_back(verticeActual); // colocar el vértice actual en la lista de visitados
                aux = verticeActual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++){
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vértice que el vértice actual tiene como destino, y que no ha sido visitado
                        pila.push(aux->getAdy()); // apilar el vértice
                        pilaPar.push(parVertices(verticeActual, aux->getAdy())); // apilar la pareja: vértice actual y vértice destino
                    }
                    aux = aux->getSig();
                }
            }
        }
        if (band3 == 0){ // si la pila se vacío sin encontrar el destino
            cout << "No hay ruta entre esos dos vértices"; // no existe una ruta entre esos vértices.
        }
    }
}




