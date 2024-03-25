#include <iostream>
#include "tablaHashGrupos/TablaGruposHash.h"
#include "ArbolesAvl//ArbolAVL.h"
#include "tablaHashCampos/TablaCampoHash.h"
#include "generarArchivos/ArchivoDOT.h"
#include <fstream>
using namespace std;


int main() {

    /*TablaGruposHash tabla;
    GrupoHash grupo1{"Clientes","Clientes"};
    GrupoHash grupo2{"Proveedores","Proveedores"};
    GrupoHash grupo3{"Trabajadores","Trabajadores"};
    GrupoHash grupo4{"Limpieza","Limpieza"};

    tabla.insertarGrupo(grupo1);
    tabla.insertarGrupo(grupo2);
    tabla.insertarGrupo(grupo3);
    tabla.insertarGrupo(grupo4);

    tabla.imprimirDatosTabla();*/
    /*ArbolAVL arbol;
    NodoArbol *raiz = nullptr;

    arbol.insertarEnArbol("Juan");
    arbol.insertarEnArbol("Pedro");
    arbol.insertarEnArbol("Julio");
    arbol.insertarEnArbol("Ramon");
    arbol.insertarEnArbol("Casas");
    arbol.insertarEnArbol("Aron");
    arbol.insertarEnArbol("Ale");
    arbol.insertarEnArbol("Sofi");
    arbol.insertarEnArbol("Marta");

    raiz = arbol.getArbol();*/

    TablaCampoHash campos;
    campos.insertarGrupo("Nombre");
    campos.insertarGrupo("Telefono");
    campos.insertarGrupo("Apellido");

    campos.insertarDatosArbol("Nombre","Juanito");
    campos.insertarDatosArbol("Nombre","Pedroporro");
    campos.insertarDatosArbol("Nombre","Juliocasas");
    campos.insertarDatosArbol("Nombre","Ramondino");
    campos.insertarDatosArbol("Nombre","Casasblanca");

    campos.insertarDatosArbol("Telefono","12378567");
    campos.insertarDatosArbol("Telefono","45647896");
    campos.insertarDatosArbol("Telefono","78965478");
    campos.insertarDatosArbol("Telefono","10135486");
    campos.insertarDatosArbol("Telefono","10236789");

    campos.insertarDatosArbol("Apellido","Aron");
    campos.insertarDatosArbol("Apellido","Astrid");
    campos.insertarDatosArbol("Apellido","Ale");
    campos.insertarDatosArbol("Apellido","Sofi");
    campos.insertarDatosArbol("Apellido","Marta");

    campos.imprimirDatosTabla();
    campos.buscarGrupo("Nombre").arbol.imprimirInOrden();
    campos.buscarGrupo("Apellido").arbol.imprimirInOrden();
    campos.buscarGrupo("Telefono").arbol.imprimirInOrden();

    NodoArbol *raiz = nullptr;
    ArchivoDOT dot;

    raiz = campos.buscarGrupo("Telefono").arbol.getArbol();


    //dot.obtenerArchivoDOT(raiz);
    dot.generarDOTCampos(campos);

    cout<<"Fin del metodo";

}
