//
// Created by rudyo on 21/03/2024.
//
#include <iostream>
#include "TablaGruposHash.h"
using namespace std;


TablaGruposHash::TablaGruposHash() {
    tabla = new GrupoHash[5];
    tamanoActual = 5;
    cantidadDatos = 0;

}

int TablaGruposHash::funcionHash(string &nombreGrupo) {
        int hash = 0;
        for (char c : nombreGrupo) {
            hash += c;
        }
        return hash % tamanoActual;

}

void TablaGruposHash::rehash() {
    int nuevoTamano = tamanoActual * 2;
    GrupoHash* nuevaTabla = new GrupoHash[nuevoTamano];

    // Copiar elementos de la tabla original a la nueva tabla
    for (int i = 0; i < tamanoActual; ++i) {
        if (!tabla[i].nombreGrupo.empty()) {
            int nuevoIndex = funcionHash(tabla[i].nombreGrupo);
            while (!nuevaTabla[nuevoIndex].nombreGrupo.empty()) {
                nuevoIndex = (nuevoIndex + 1) % nuevoTamano;
            }
            nuevaTabla[nuevoIndex] = tabla[i];
        }
    }

    // Eliminar la tabla original y actualizar punteros y tamanio
    delete[] tabla;
    tabla = nuevaTabla;
    tamanoActual = nuevoTamano;

}

void TablaGruposHash::insertarGrupo(GrupoHash grupo) {

        // Verificar si es necesario realizar rehashing
        if ((double)cantidadDatos / tamanoActual >= factorCarga) {
            rehash();
        }

        // Calcular el índice de hash
        unsigned int index = funcionHash(grupo.nombreGrupo);

        // Manejar colisiones y encontrar una posición vacía
        while (!tabla[index].nombreGrupo.empty()) {
            index = (index + 1) % tamanoActual;
        }

        // Insertar el elemento en la tabla
        tabla[index] = grupo;
        cantidadDatos++;

}

GrupoHash TablaGruposHash::buscarGrupo(string nombreGrupo) {
    int index = funcionHash(nombreGrupo);
    GrupoHash encontrado;
    if(!tabla[index].nombreGrupo.empty()){
        encontrado = tabla[index];
    }

    return encontrado;
}

int TablaGruposHash::obtenerPosicionGrupo(string nombreGrupo) {
    return funcionHash(nombreGrupo);
}

GrupoHash *TablaGruposHash::obtenerTabla() {
    return tabla;
}

void TablaGruposHash::imprimirDatosTabla() {
    cout << "Datos almacenados en la tabla hash:" <<endl;
    cout << "Datos almacenados tiene un tamanio de : "<<tamanoActual <<endl;
    for (int i = 0; i < tamanoActual; ++i) {
        if (!tabla[i].nombreGrupo.empty()) {
            cout << "Clave: " << tabla[i].nombreGrupo << ", Valor: " << tabla[i].valor << " , indice" << funcionHash(tabla[i].nombreGrupo) <<endl;
        }
    }
}
