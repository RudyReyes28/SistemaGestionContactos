//
// Created by rudyo on 24/03/2024.
//

#include "TablaCampoHash.h"

TablaCampoHash::TablaCampoHash() {
    tabla = new CampoHash[5];
    tamanoActual = 5;
    cantidadDatos = 0;
}

int TablaCampoHash::funcionHash(string &nombreCampo) {
    int hash = 0;
    for (char c : nombreCampo) {
        hash += c;
    }
    return hash % tamanoActual;
}

void TablaCampoHash::rehash() {
    int tamanoAnterior = tamanoActual;
    int nuevoTamano = tamanoActual * 2;
    tamanoActual = nuevoTamano;
    CampoHash* nuevaTabla = new CampoHash[nuevoTamano];

    // Copiar elementos de la tabla original a la nueva tabla
    for (int i = 0; i < tamanoAnterior; ++i) {
        if (!tabla[i].nombreCampo.empty()) {
            int nuevoIndex = funcionHash(tabla[i].nombreCampo);
            //cout<<"entramos al generaodor index "<<tabla[i].nombreCampo<< i<<endl;
            while (!nuevaTabla[nuevoIndex].nombreCampo.empty()) {
                //cout<<"entramos al generaodor index "<<tabla[i].nombreCampo<<endl;
                nuevoIndex = (nuevoIndex + 1) % nuevoTamano;
            }
            nuevaTabla[nuevoIndex] = tabla[i];
        }
    }

    // Eliminar la tabla original y actualizar punteros y tamanio
    delete[] tabla;
    tabla = nuevaTabla;


}

void TablaCampoHash::insertarGrupo(string nombreCampo, string tipoDato) {
    // Verificar si es necesario realizar rehashing
    if ((double)cantidadDatos / tamanoActual >= factorCarga) {
        rehash();
    }

    // Calcular el índice de hash
    unsigned int index = funcionHash(nombreCampo);

    // Manejar colisiones y encontrar una posición vacía
    while (!tabla[index].nombreCampo.empty()) {
        index = (index + 1) % tamanoActual;
    }

    // Insertar el elemento en la tabla
    CampoHash nuevoCampo;
    nuevoCampo.nombreCampo = nombreCampo;
    nuevoCampo.tipoDato = tipoDato;
    nuevoCampo.indiceCampo = cantidadDatos+1;
    tabla[index] = nuevoCampo;
    cantidadDatos++;
}

CampoHash TablaCampoHash::buscarGrupo(string nombreCampo) {
    int index = funcionHash(nombreCampo);
    CampoHash encontrado;
    if(!tabla[index].nombreCampo.empty()){
        encontrado = tabla[index];
    }

    return encontrado;
}

int TablaCampoHash::obtenerPosicionGrupo(string nombreCampo) {
    return funcionHash(nombreCampo);
}

CampoHash *TablaCampoHash::obtenerTabla() {
    return tabla;
}

void TablaCampoHash::imprimirDatosTabla() {
    cout << "Datos almacenados en la tabla hash:" << cantidadDatos<<endl;
    cout << "Datos almacenados tiene un tamanio de : "<<tamanoActual <<endl;
    for (int i = 0; i < tamanoActual; ++i) {
        if (!tabla[i].nombreCampo.empty()) {
            cout << "Clave: " << tabla[i].nombreCampo<<" Tipo de Dato: "<<tabla[i].tipoDato << ", Valor: " << tabla[i].indiceCampo << " , indice" << funcionHash(tabla[i].nombreCampo) <<endl;
        }
    }
}

void TablaCampoHash::insertarDatosArbol(string nombreCampo, string valor) {
    int index = funcionHash(nombreCampo);

    if(!tabla[index].nombreCampo.empty()){
        tabla[index].arbol.insertarEnArbol(valor);
    }
}

void TablaCampoHash::insertarDatosArbolPosicion(int posicion, string valor) {

    for(int i=0; i<tamanoActual;i++){
        if(!tabla[i].nombreCampo.empty()){
            if(tabla[i].indiceCampo==posicion){
                tabla[i].arbol.insertarEnArbol(valor);
                break;
            }
        }
    }

}

int TablaCampoHash::getTamanoTabla() {
    return tamanoActual;
}

string TablaCampoHash::obtenerNombreCampo(int valor) {
    string nombreCampo = "";
    for (int i = 0; i < tamanoActual; ++i) {
        if (!tabla[i].nombreCampo.empty()) {
            if(tabla[i].indiceCampo == valor){
                nombreCampo= tabla[i].nombreCampo;
                break;
            }
        }
    }

    return nombreCampo;
}

int TablaCampoHash::obtenerCantidadDatos() {
    return cantidadDatos;
}

int TablaCampoHash::obtenerCantidadDatosArbol() {

    for (int i = 0; i < tamanoActual; ++i) {
        if (!tabla[i].nombreCampo.empty()) {
            return tabla[i].arbol.obtenerNumeroDeDatos();
        }
    }

    return 0;
}




