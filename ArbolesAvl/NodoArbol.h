//
// Created by rudyo on 24/03/2024.
//

#ifndef GESTIONDECONTACTOS_NODOARBOL_H
#define GESTIONDECONTACTOS_NODOARBOL_H
#include <string>
using namespace std;
struct NodoArbol{
    string dato;
    int valor;
    NodoArbol* der;
    NodoArbol* izq;
    int altura;
};


#endif //GESTIONDECONTACTOS_NODOARBOL_H
