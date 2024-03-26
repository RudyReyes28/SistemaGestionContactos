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

    //string comando = "ADD NEW-GROUP proveedores FIELDS (empresa STRING, direccion STRING, tel1 INTEGER, categoria CHAR);";
    string comando = "ADD NEW-GROUP friends FIELDS (nombre STRING, apodo STRING, celular INTEGER, cumpleanios DATE, apellido STRING, correo STRING);";

    /*vector<pair<string,string>> campos = creacionDeGruposComando(comando);

    // Imprimir los resultados
    for (const auto& campo : campos) {
        cout << "Campo: " << campo.first << " Tipo de dato: " << campo.second <<endl;
    }*/

    string contacto = "ADD CONTACT IN amigos FIELDS (Pedro, Alvarez, 12345678, 02-05-1998), marta, A, carla);";
    vector<string> contactos = insercionContactosComando(contacto);

    string buscar = "FIND CONTACT IN clientes CONTACT-FIELD cumpleanios=2020-21-10;";
    vector<string> busqueda = busquedaContactosComando(buscar);
    for(int i=0; i<busqueda.size(); i++){
        cout<<"dato: "<<busqueda[i]<<endl;
    }

     return 0;

}
