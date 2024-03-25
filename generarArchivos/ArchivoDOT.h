//
// Created by rudyo on 24/03/2024.
//

#ifndef GESTIONDECONTACTOS_ARCHIVODOT_H
#define GESTIONDECONTACTOS_ARCHIVODOT_H

#include "../ArbolesAvl/NodoArbol.h"
#include "../tablaHashCampos/TablaCampoHash.h"
#include <iostream>
#include <fstream>
class ArchivoDOT{
public:
    void generarArchivoDOT(NodoArbol* raiz, ofstream& archivoDot);
    void obtenerArchivoDOT(NodoArbol *raiz);
    void generarDOTCampos(TablaCampoHash tabla);
};
#endif //GESTIONDECONTACTOS_ARCHIVODOT_H