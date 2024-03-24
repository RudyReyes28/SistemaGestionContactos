//
// Created by rudyo on 21/03/2024.
//

#ifndef GESTIONDECONTACTOS_TABLAGRUPOSHASH_H
#define GESTIONDECONTACTOS_TABLAGRUPOSHASH_H
#include <iostream>
#include "GrupoHash.h"


class TablaGruposHash{

private:
    double factorCarga = 0.6;
    GrupoHash* tabla;
    int tamanoActual;
    int cantidadDatos;
    int funcionHash(string& nombreGrupo);
    void rehash();
public:
    TablaGruposHash();
    ~TablaGruposHash() {
        delete[] tabla;
    }

    void insertarGrupo(GrupoHash grupo);
    GrupoHash buscarGrupo(string nombreGrupo);
    int obtenerPosicionGrupo(string nombreGrupo);
    GrupoHash* obtenerTabla();
    void imprimirDatosTabla();
};

#endif //GESTIONDECONTACTOS_TABLAGRUPOSHASH_H
