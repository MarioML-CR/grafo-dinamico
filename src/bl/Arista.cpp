//
// Created by Mario Martinez on 19/11/20.
//

#include "Arista.h"

Arista::Arista(int peso) : peso(peso) {
    setPeso(peso);
    setAdy(nullptr);
    setSig(nullptr);
}

Arista::~Arista() {

}

int Arista::getPeso() const {
    return peso;
}

void Arista::setPeso(int peso) {
    Arista::peso = peso;
}

Arista *Arista::getSig() const {
    return sig;
}

void Arista::setSig(Arista *sig) {
    Arista::sig = sig;
}

Vertice *Arista::getAdy() const {
    return ady;
}

void Arista::setAdy(Vertice *ady) {
    Arista::ady = ady;
}
