//
// Created by rudyo on 24/03/2024.
//

#ifndef GESTIONDECONTACTOS_CAMPOHASH_H
#define GESTIONDECONTACTOS_CAMPOHASH_H
#include <string>
#include "../ArbolesAvl/ArbolAVL.h"

using namespace std;
struct CampoHash{
    string nombreCampo; //clave
    string tipoDato;
    ArbolAVL arbol; //tabla hash asociada al arbol
    int indiceCampo;

};

#endif //GESTIONDECONTACTOS_CAMPOHASH_H
