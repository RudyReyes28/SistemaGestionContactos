#include <iostream>
#include "tablaHashGrupos/TablaGruposHash.h"
#include "ArbolesAvl//ArbolAVL.h"
#include "tablaHashCampos/TablaCampoHash.h"
#include "generarArchivos/ArchivoDOT.h"
#include "lineaDeComandos/LineaComandos.h"
#include "exportacionContactos/ExportarContacto.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/*
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
  */


//NodoArbol *raiz = nullptr;
//ArchivoDOT dot;

//raiz = tabla.buscarGrupo("Clientes").campos.buscarGrupo("nombre").arbol.getArbol();
//dot.obtenerArchivoDOT(raiz);
void opcionCreacionDeGrupos(TablaGruposHash &tabla){
    string comando;
    cout<<"Digite el comando para crear un nuevo grupo: "<<endl;
    getline(cin, comando);
    vector<pair<string,string>> campos = creacionDeGruposComando(comando);
    if (campos.empty()) {
        cout << "El comando no es correcto." << endl;
    } else {
        //cout << "Nombre: " << campos[0].first << endl;
        string nombreG =  campos[0].first;
        tabla.insertarGrupoPorNombre( nombreG);
        for(int i = 1; i < campos.size(); i++){
            //cout << "Campo: " << campos[i].first << " tipo: " << campos[i].second << endl;
            tabla.insertarCamposGrupo(nombreG,campos[i].first, campos[i].second);
        }

        /*cout<<endl;
        tabla.imprimirDatosTabla();
        cout<<endl;
        tabla.buscarGrupo(nombreG).campos->imprimirDatosTabla();*/


    }

}

void opcionInsercionDeContactos(TablaGruposHash &tabla){
    string comando;
    cout<<"Digite el comando para ingresar un nuevo contacto: "<<endl;
    getline(cin, comando);
    vector<string> contactos = insercionContactosComando(comando);
    if (contactos.empty()) {
        cout << "El comando no es correcto." << endl;
    } else {
        string nombreG =  contactos[0];

        for(int i = 1; i < contactos.size(); i++){
            string nombreCampo = tabla.buscarGrupo(nombreG).campos->obtenerNombreCampo(i);
            cout<<nombreCampo<< " : "<<contactos[i]<<endl;
            tabla.insertarDatosCampos(nombreG,nombreCampo,contactos[i]);
        }

    }
}

void opcionBusquedaDeContactos(TablaGruposHash &tabla){
    string comando;
    cout<<"Digite el comando para buscar un contacto: "<<endl;
    getline(cin, comando);
    vector<string> busqueda = busquedaContactosComando(comando);

    if (busqueda.empty()) {
        cout << "El comando no es correcto." << endl;
    } else {
        string nombreG = busqueda[0];
        string campo = busqueda[1];
        string valor = busqueda[2];
        int valorNodo = tabla.buscarGrupo(nombreG).campos->buscarGrupo(campo).arbol.obtenerValorNodoArbol(valor);
        int cantidadDatos = tabla.buscarGrupo(nombreG).campos->obtenerCantidadDatos();

        string datosContacto = "";
        for(int i=1; i<= cantidadDatos; i++){
            string nombreCampo = tabla.buscarGrupo(nombreG).campos->obtenerNombreCampo(i);
            datosContacto+= nombreCampo+": ";
            string dato = tabla.buscarGrupo(nombreG).campos->buscarGrupo(nombreCampo).arbol.obtenerDatoNodoArbol(valorNodo);
            datosContacto+=dato+"\n";

        }
        cout<<datosContacto<<endl;

    }
}

void opcionExportarContactos(){
    //string folderName = "../mi_carpeta";
    string nombreCarpeta = "../clientes";
    string nombreArchivo = "roman";
    string contacto = "nombre: roman\napellido:vasquez\ntelefono:45789632";
    generarCarpeta(nombreCarpeta);

    exportarContacto(nombreCarpeta,nombreArchivo,contacto);


}

int main() {
    TablaGruposHash tabla;

    int opcion = 0;
    do{

        cout<<"--------------- GESTION DE CONTACTOS ---------------"<<endl;
        cout<<endl;
        cout<<"-->Terminal o Consola de Lenguaje de Comunicacion"<<endl;
        cout<<"      1. Creacion de Grupos"<<endl;
        cout<<"      2. Insercion de Contactos"<<endl;
        cout<<"      3. Busqueda de Contactos"<<endl;
        cout<<"-->Menu de reportes"<<endl;
        cout<<"      4. Ver reportes"<<endl;
        cout<<"-->Graficas de las Estructuras"<<endl;
        cout<<"      4. Estado actual de toda la estructura completa"<<endl;
        cout<<"      5. Estado actual de cada una de las estructuras por separado"<<endl;
        cout<<"      6. Estado actual de los datos de un grupo"<<endl;
        cout<<"-->Exportacion de contactos"<<endl;
        cout<<"      7. Exportar Contactos"<<endl;
        cout<<"-->Cerrar Programa"<<endl;
        cout<<"      8. Salir"<<endl;
        cout<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                //METODO PARA OBTENER LOS DATOS
                //ADD NEW-GROUP Clientes FIELDS (nombre STRING, apellido STRING, telefono INTEGER);
                opcionCreacionDeGrupos(tabla);
                break;
            case 2:
                //ADD CONTACT IN Clientes FIELDS (Pedro, Alvarez, 12345678);
                //ADD CONTACT IN Clientes FIELDS (Juan, Perez, 98765432);
                //ADD CONTACT IN Clientes FIELDS (Maria, Garcia, 65432198);
                //ADD CONTACT IN Clientes FIELDS (Luis, Gonzalez, 12348765);
                //ADD CONTACT IN Clientes FIELDS (Ana, Martinez, 78901234);
                opcionInsercionDeContactos(tabla);
                break;
            case 3:
                //FIND CONTACT IN Clientes CONTACT-FIELD nombre=Pedro;
                opcionBusquedaDeContactos(tabla);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                opcionExportarContactos();
                break;

        }

    }while(opcion != 8);
    //tabla.imprimirDatosTabla();
    //tabla.buscarGrupo("Clientes").campos->buscarGrupo("nombre").arbol.imprimirInOrden();
    //tabla.buscarGrupo("Clientes").campos->buscarGrupo("telefono").arbol.imprimirInOrden();
     return 0;

}
