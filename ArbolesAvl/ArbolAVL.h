//
// Created by rudyo on 24/03/2024.
//

#ifndef GESTIONDECONTACTOS_ARBOLAVL_H
#define GESTIONDECONTACTOS_ARBOLAVL_H
#include <iostream>
#include "NodoArbol.h"

class ArbolAVL{
private:
    int numeroDato;
    NodoArbol* arbol;
    int altura(NodoArbol* nodo );
    int maxNum(int a, int b);
    NodoArbol* nuevoNodo(string &valor);
    NodoArbol* rotarDer(NodoArbol* y);
    NodoArbol* rotarIzq(NodoArbol* x);
    int balance(NodoArbol *nodo);
    NodoArbol* insertar(NodoArbol *nodo, string &valor);

public:
    ArbolAVL();
    void preOrden(NodoArbol* raiz);
    void inOrden(NodoArbol * raiz);
    void postOrden(NodoArbol* raiz);
    void insertarEnArbol(string valor);
    NodoArbol* getArbol();
};
#endif //GESTIONDECONTACTOS_ARBOLAVL_H
