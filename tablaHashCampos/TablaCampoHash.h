//
// Created by rudyo on 24/03/2024.
//

#ifndef GESTIONDECONTACTOS_TABLACAMPOHASH_H
#define GESTIONDECONTACTOS_TABLACAMPOHASH_H

#include "CampoHash.h"

class TablaCampoHash{
private:
    double factorCarga = 0.6;
    CampoHash* tabla;
    int tamanoActual;
    int cantidadDatos;
    int funcionHash(string& nombreCampo);
    void rehash();
public:
    TablaCampoHash();
    ~TablaCampoHash() {
        delete[] tabla;
    }
    void insertarGrupo(string nombreCampo, string tipoDato);
    CampoHash buscarGrupo(string nombreCampo);
    int obtenerPosicionGrupo(string nombreCampo);
    CampoHash* obtenerTabla();
    void imprimirDatosTabla();
    void insertarDatosArbol(string nombreCampo, string valor);
    void insertarDatosArbolPosicion(int posicion, string valor);
    string obtenerNombreCampo(int valor);
    int getTamanoTabla();
    int obtenerCantidadDatos();
    int obtenerCantidadDatosArbol();
};

#endif //GESTIONDECONTACTOS_TABLACAMPOHASH_H
