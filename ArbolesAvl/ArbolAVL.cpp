//
// Created by rudyo on 24/03/2024.
//

#include "ArbolAVL.h"

int ArbolAVL::altura(NodoArbol *nodo) {
    if(nodo== nullptr){
        return 0;
    }
    return nodo->altura;
}

int ArbolAVL::maxNum(int a, int b) {
    return (a>b)? a:b;
}

NodoArbol *ArbolAVL::nuevoNodo(string &valor) {
    NodoArbol* nuevoNodo = new NodoArbol();
    nuevoNodo->dato = valor;
    nuevoNodo->valor = numeroDato;
    nuevoNodo->der = nullptr;
    nuevoNodo->izq = nullptr;
    nuevoNodo->altura = 1;

    numeroDato++;
    return nuevoNodo;
}

NodoArbol *ArbolAVL::rotarDer(NodoArbol *y) {
    NodoArbol *x = y->izq;
    NodoArbol *temp = x->der;
    x->der = y;
    y->izq = temp;

    y->altura = maxNum(altura(y->izq), altura(y->der))+1;
    x->altura = maxNum(altura(x->izq), altura(x->der))+1;
    return x;
}

NodoArbol *ArbolAVL::rotarIzq(NodoArbol *x) {
    NodoArbol *y = x->der;
    NodoArbol *temp = y->izq;
    y->izq = x;
    x->der = temp;

    x->altura = maxNum(altura(x->izq), altura(x->der))+1;
    y->altura = maxNum(altura(y->izq), altura(y->der))+1;
    return y;
}

int ArbolAVL::balance(NodoArbol *nodo) {
    if(nodo== nullptr){
        return 0;
    }
    return altura(nodo->izq)- altura(nodo->der);
}

NodoArbol *ArbolAVL::insertar(NodoArbol *nodo, string &valor) {
    if(nodo== nullptr){
        return (nuevoNodo(valor));
    }
    if(numeroDato< nodo->valor){
        nodo->izq = insertar(nodo->izq,valor);
    }else if(numeroDato>nodo->valor){
        nodo->der= insertar(nodo->der,valor);
    }

    nodo->altura = 1+ maxNum(altura(nodo->izq), altura(nodo->der));
    int equilibrio = balance(nodo);
    //CASOS
    //IZQUIERDA IZQUIERDA
    if(equilibrio>1 && numeroDato< nodo->izq->valor){
        return rotarDer(nodo);

        //DERECHA DERECHA
    }
    if(equilibrio<-1 && numeroDato>nodo->der->valor){
        return rotarIzq(nodo);
        //izquierda derecha
    }
    if(equilibrio >1 && numeroDato > nodo->izq->valor){
        nodo->izq = rotarIzq(nodo->izq);
        return rotarDer(nodo);
        //derecha izquierda
    }
    if(equilibrio<-1 && numeroDato<nodo->der->valor){
        nodo->der = rotarDer(nodo->der);
        return rotarIzq(nodo);
    }

    return nodo;
}

void ArbolAVL::preOrden(NodoArbol *raiz) {
    if(raiz!= nullptr){
        cout<<" ->"<<raiz->dato<< endl;
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void ArbolAVL::inOrden(NodoArbol *raiz) {
    if(raiz!= nullptr){
        inOrden(raiz->izq);
        cout<<" ->"<<raiz->dato<< endl;
        inOrden(raiz->der);
    }
}

void ArbolAVL::postOrden(NodoArbol *raiz) {
    if(raiz!= nullptr){
        postOrden(raiz->izq);
        postOrden(raiz->der);
        cout<<" ->"<<raiz->valor<< endl;
    }
}

void ArbolAVL::insertarEnArbol(string valor) {
    arbol = insertar(arbol,valor);
}

ArbolAVL::ArbolAVL() {
    arbol = nullptr;
    numeroDato = 1;
}

NodoArbol *ArbolAVL::getArbol() {
    return arbol;
}

void ArbolAVL::imprimirInOrden() {
    inOrden(arbol);

}



