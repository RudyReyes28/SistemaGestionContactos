//
// Created by rudyo on 24/03/2024.
//

#ifndef GESTIONDECONTACTOS_ARCHIVODOT_H
#define GESTIONDECONTACTOS_ARCHIVODOT_H

#include "../ArbolesAvl/NodoArbol.h"
#include "../tablaHashCampos/TablaCampoHash.h"
#include "../tablaHashGrupos/TablaGruposHash.h"
#include <iostream>
#include <fstream>
class ArchivoDOT{
public:
    void generarArchivoDOT(NodoArbol* raiz, ofstream& archivoDot);
    void obtenerArchivoDOT(NodoArbol *raiz);
    void graficarArbolesGrupo(string nombreG,TablaGruposHash &tabla);
    void archivoDOTTablaCampos(ofstream& archivoDot, TablaGruposHash &tabla);
    void archivoDOTTablaHashGlobal(ofstream& archivoDot, TablaGruposHash &tabla);
    void graficarTablaHashGlobal(TablaGruposHash &tabla);
    void archivoDOTCamposGrupo(ofstream& archivoDot, string nombre, TablaGruposHash &tabla);
    void graficarGrupoHash(string nombre, TablaGruposHash &tabla);
};
#endif //GESTIONDECONTACTOS_ARCHIVODOT_H
