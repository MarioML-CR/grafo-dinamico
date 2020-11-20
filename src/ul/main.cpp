#include <iostream>
#include "../tl/Gestor.h"
#include "utilitario/Validar.h"

using namespace std;

Gestor gestor;
Validar validar;
void menu();
void procesarMenu(int &, bool &);
int ingresarNum(string);
void insertVertice();
void insertaArista();
void insertVerticeUser();
void insertaAristaUser();
void listaAdyacencia();
void eliminarArista();
void eliminarVertice();
void eliminarGrafo();
void tamanio();
void recorridoAnchura();
void recorridoProfundidad();

int main() {
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú Árbol\n\nElija una opción\n" <<
             "01 Agregar vértice (auto)\n" <<
             "02 Agregar aristas (auto)\n" <<
             "03 Agregar aristas (usuario)\n" <<
             "04 Agregar aristas (usuario)\n" <<
             "05 Imprimir\n" <<
             "06 Tamaño\n" <<
             "07 Eliminar vértice\n" <<
             "08 Eliminar arista\n" <<
             "09 Eliminar grafo\n" <<
             "10 Recorrido en anchura\n" <<
             "11 Recorrido en profundidad\n" <<
             "12 Primero mejor\n" <<
             "13 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            insertVertice();
            break;
        case 2:
            insertaArista();
            break;
        case 3:
            insertVerticeUser();
            break;
        case 4:
            insertaAristaUser();
            break;
        case 5:
            listaAdyacencia();
            break;
        case 6:
            tamanio();
            break;
        case 7:
            eliminarVertice();
            break;
        case 8:
            eliminarArista();
            break;
        case 9:
            eliminarGrafo();
            break;
        case 10:
            recorridoAnchura();
            break;
        case 11:
            recorridoProfundidad();
            break;
        case 12:
//            listaAdyacencia();
            break;
        case 13:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
int ingresarNum(string msg){
    int num;
    string valor;
    do {
        cout << msg << endl;
        cin >> valor;
        num = validar.ingresarInt(valor);
        if (num == -1){
            cout << "El valor ingresado es incorrecto\nVuelva a intentarlo\n";
        }
    } while (num == -1);
    return num;
}
void insertVertice(){
//    gestor.insertVertice("Guadalajara");
//    gestor.insertVertice("Puebla");
//    gestor.insertVertice("DF");
//    gestor.insertVertice("Zacatecas");
//    gestor.insertVertice("Michoacan");
//    gestor.insertVertice("Los Cabos");


    gestor.insertVertice("A");
    gestor.insertVertice("B");
    gestor.insertVertice("C");
    gestor.insertVertice("D");
    gestor.insertVertice("E");
    gestor.insertVertice("F");
    gestor.insertVertice("G");

}
void insertaArista(){
//    gestor.insertaArista("Guadalajara", "DF", 500);
//    gestor.insertaArista("Guadalajara", "Zacatecas", 200);
//    gestor.insertaArista("Guadalajara", "Los Cabos", 600);
//    gestor.insertaArista("Puebla", "Michoacan", 100);
//    gestor.insertaArista("Puebla", "DF", 500);
//    gestor.insertaArista("DF", "Los Cabos", 200);
//    gestor.insertaArista("Zacatecas", "Puebla", 300);
//    gestor.insertaArista("Zacatecas", "Los Cabos", 800);
//    gestor.insertaArista("Michoacan", "Guadalajara", 400);
//    gestor.insertaArista("Michoacan", "DF", 300);
//    gestor.insertaArista("Los Cabos", "Michoacan", 300);

    gestor.insertaArista("A", "A", 13);
    gestor.insertaArista("A", "D", 18);
    gestor.insertaArista("B", "B", 52);
    gestor.insertaArista("B", "C", 17);
    gestor.insertaArista("B", "D", 83);
    gestor.insertaArista("B", "F", 97);
    gestor.insertaArista("B", "G", 60);
    gestor.insertaArista("C", "A", 4);
    gestor.insertaArista("D", "B", 97);
    gestor.insertaArista("D", "C", 37);
    gestor.insertaArista("D", "D", 22);
    gestor.insertaArista("D", "E", 41);
    gestor.insertaArista("D", "G", 64);
    gestor.insertaArista("E", "B", 8);
    gestor.insertaArista("E", "E", 45);
    gestor.insertaArista("E", "F", 92);
    gestor.insertaArista("F", "A", 8);
    gestor.insertaArista("F", "B", 45);
    gestor.insertaArista("F", "E", 42);
    gestor.insertaArista("G", "D", 17);
}
void insertVerticeUser(){

}
void insertaAristaUser(){

}
void listaAdyacencia(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        cout << "La lista de adyacencia es...\n";
        gestor.listaAdyacencia();
    }
}
void eliminarVertice(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string vertice;
        cout << "Ingrese el nombre del vértice que desea eliminar\n";
        cin >> vertice;
        cout << gestor.eliminarVertice(vertice);
    }
}
void eliminarArista(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string salida, llegada;
        cout << "Ingrese la ciudad de salida\n";
//        getline(cin, salida, '\n');
        cin >> salida;
        cout << "Ingrese la ciudad de llegada\n";
//        getline(cin, llegada, '\n');
        cin >> llegada;
        gestor.eliminarArista(salida, llegada);
        cout << "Proceso completado satisfactoriamente\n";
    }

}
void eliminarGrafo(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        gestor.anular();
    }

}
void tamanio(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        cout << "La matriz de adyacencia tiene " + to_string(gestor.tamanio()) + " vértices\n";
    }
}
void recorridoAnchura(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string nombre;
        cout << "Ingrese el nombre del vértice inicial\n";
        cin.ignore();
        getline(cin, nombre, '\n');
        gestor.recorridoAnchura(nombre);
    }
}
void recorridoProfundidad(){
    if (gestor.vacio()){
        cout << "Aún no se han ingresado vértices...\n";
    } else {
        string nombre;
        cout << "Ingrese el nombre del vértice inicial\n";
        cin.ignore();
        getline(cin, nombre, '\n');
        gestor.recorridoProfundidad(nombre);
    }
}