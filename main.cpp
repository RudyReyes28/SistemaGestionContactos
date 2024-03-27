#include <iostream>
#include "tablaHashGrupos/TablaGruposHash.h"
#include "ArbolesAvl//ArbolAVL.h"
#include "tablaHashCampos/TablaCampoHash.h"
#include "generarArchivos/ArchivoDOT.h"
#include "lineaDeComandos/LineaComandos.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

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

/*TablaCampoHash campos;
campos.insertarGrupo("Nombre", "STRING");
campos.insertarGrupo("Telefono", "INTEGER");
campos.insertarGrupo("Apellido","STRING");
campos.insertarGrupo("Apodos","STRING");
campos.imprimirDatosTabla();*/

/*campos.insertarDatosArbol("Nombre","Juanito");
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
campos.buscarGrupo("Telefono").arbol.imprimirInOrden();*/

//NodoArbol *raiz = nullptr;
//ArchivoDOT dot;

//raiz = campos.buscarGrupo("Telefono").arbol.getArbol();


//dot.obtenerArchivoDOT(raiz);
//dot.generarDOTCampos(campos);

//cout<<"Fin del metodo";
/*
    TablaGruposHash tabla;

    tabla.insertarGrupoPorNombre("Clientes");
    tabla.insertarGrupoPorNombre("Proveedores");
    tabla.insertarGrupoPorNombre("Trabajadores");
    tabla.imprimirDatosTabla();*/


/*tabla.insertarCamposGrupo("Clientes","nombre","STRING");
tabla.insertarCamposGrupo("Clientes","apellido","STRING");
tabla.insertarCamposGrupo("Clientes","telefono","INTEGER");

tabla.insertarDatosCampos("Clientes","nombre","Juana");
tabla.insertarDatosCampos("Clientes","nombre","Pedro");
tabla.insertarDatosCampos("Clientes","nombre","Julian");
tabla.insertarDatosCampos("Clientes","nombre","Marta");
tabla.insertarDatosCampos("Clientes","nombre","Carlos");*/


//NodoArbol *raiz = nullptr;
//ArchivoDOT dot;

//raiz = tabla.buscarGrupo("Clientes").campos.buscarGrupo("nombre").arbol.getArbol();
//dot.obtenerArchivoDOT(raiz);
int main() {
    TablaGruposHash tabla;

    tabla.insertarGrupoPorNombre("Clientes");
    tabla.insertarGrupoPorNombre("Trabajadores");
    tabla.insertarGrupoPorNombre("Proveedores");

    tabla.insertarCamposGrupo("Clientes","nombre","STRING");
    tabla.insertarCamposGrupo("Clientes","apellido","STRING");
    tabla.insertarCamposGrupo("Clientes","telefono","INTEGER");


    tabla.insertarDatosCampos("Clientes","nombre","Juana");
    tabla.insertarDatosCampos("Clientes","nombre","Pedro");
    tabla.insertarDatosCampos("Clientes","nombre","Julian");
    tabla.insertarDatosCampos("Clientes","nombre","Marta");
    tabla.insertarDatosCampos("Clientes","nombre","Carlos");

    tabla.insertarDatosCampos("Clientes","telefono","12378567");
    tabla.insertarDatosCampos("Clientes","telefono","78121456");
    tabla.insertarDatosCampos("Clientes","telefono","74821471");
    tabla.insertarDatosCampos("Clientes","telefono","78164321");
    tabla.insertarDatosCampos("Clientes","telefono","71295304");

    tabla.buscarGrupo("Clientes").campos->buscarGrupo("nombre").arbol.imprimirInOrden();
    tabla.buscarGrupo("Clientes").campos->buscarGrupo("telefono").arbol.imprimirInOrden();

    cout<<endl;
    tabla.imprimirDatosTabla();


    tabla.insertarGrupoPorNombre("Empresarios");

    tabla.insertarCamposGrupo("Proveedores","nombre","STRING");
    tabla.insertarCamposGrupo("Proveedores","apellido","STRING");
    tabla.insertarCamposGrupo("Proveedores","telefono","INTEGER");


    tabla.insertarDatosCampos("Proveedores","nombre","Juana");
    tabla.insertarDatosCampos("Proveedores","nombre","Pedro");
    tabla.insertarDatosCampos("Proveedores","nombre","Julian");
    tabla.insertarDatosCampos("Proveedores","nombre","Marta");
    tabla.insertarDatosCampos("Proveedores","nombre","Carlos");

    tabla.insertarDatosCampos("Proveedores","telefono","12378567");
    tabla.insertarDatosCampos("Proveedores","telefono","78121456");
    tabla.insertarDatosCampos("Proveedores","telefono","74821471");
    tabla.insertarDatosCampos("Proveedores","telefono","78164321");
    tabla.insertarDatosCampos("Proveedores","telefono","71295304");

    cout<<"Imprimiendo proveedores"<<endl;
    tabla.buscarGrupo("Proveedores").campos->buscarGrupo("nombre").arbol.imprimirInOrden();
    tabla.buscarGrupo("Proveedores").campos->buscarGrupo("telefono").arbol.imprimirInOrden();
    cout<<endl;
    tabla.imprimirDatosTabla();


     return 0;

}
