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
    int tamanoAnterior = tamanoActual;
    int nuevoTamano = tamanoActual * 2;
    tamanoActual = nuevoTamano;
    GrupoHash* nuevaTabla = new GrupoHash[nuevoTamano];

    // Copiar elementos de la tabla original a la nueva tabla
    for (int i = 0; i < tamanoAnterior; ++i) {
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
    cout << "Datos almacenados en la tabla hash:" <<cantidadDatos<<endl;
    cout << "Datos almacenados tiene un tamanio de : "<<tamanoActual <<endl;
    for (int i = 0; i < tamanoActual; ++i) {
        if (!tabla[i].nombreGrupo.empty()) {
            cout << "Clave: " << tabla[i].nombreGrupo << " , indice" << funcionHash(tabla[i].nombreGrupo) <<endl;
        }
    }
}

void TablaGruposHash::insertarGrupoPorNombre(string nombreGrupo) {
// Verificar si es necesario realizar rehashing
    if ((double)cantidadDatos / tamanoActual >= factorCarga) {
        rehash();
    }

    // Calcular el índice de hash
    unsigned int index = funcionHash(nombreGrupo);

    // Manejar colisiones y encontrar una posición vacía
    while (!tabla[index].nombreGrupo.empty()) {
        index = (index + 1) % tamanoActual;
    }

    // Insertar el elemento en la tabla
    GrupoHash nuevoGrupo;
    nuevoGrupo.nombreGrupo = nombreGrupo;
    nuevoGrupo.campos = new TablaCampoHash();
    nuevoGrupo.valor = nombreGrupo;

    tabla[index] = nuevoGrupo;
    cantidadDatos++;
}

void TablaGruposHash::insertarCamposGrupo(string nombreGrupo, string campo, string tipoDato) {
    int index = funcionHash(nombreGrupo);
    tabla[index].campos->insertarGrupo(campo, tipoDato);
}

void TablaGruposHash::insertarDatosCampos(string nombreGrupo, string campo, string valor) {
    int index = funcionHash(nombreGrupo);
    tabla[index].campos->insertarDatosArbol(campo,valor);
}
