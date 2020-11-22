//
// Created by Mario Martinez on 19/11/20.
//
#include "Arista.h"
#include "Vertice.h"

//Vertice::Vertice(const string &nombre) : nombre(nombre) {
//    setNombre(nombre);
//    setSig(nullptr);
//    setAdy(nullptr);
//}
Vertice::Vertice(int valor, const string &nombre, Vertice *sig, Arista *ady): valor(valor), nombre(nombre), sig(sig),
                                                                               ady(ady) {
    setValor(valor);
    setNombre(nombre);
}

Vertice::~Vertice() {

}

const string &Vertice::getNombre() const {
    return nombre;
}

void Vertice::setNombre(const string &nombre) {
    Vertice::nombre = nombre;
}

Vertice *Vertice::getSig() const {
    return sig;
}

void Vertice::setSig(Vertice *sig) {
    Vertice::sig = sig;
}

Arista *Vertice::getAdy() const {
    return ady;
}

void Vertice::setAdy(Arista *ady) {
    Vertice::ady = ady;
}

int Vertice::getValor() const {
    return valor;
}

void Vertice::setValor(int valor) {
    Vertice::valor = valor;
}




