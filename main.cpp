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

    tabla.insertarCamposGrupo("Clientes","nombreC","STRING");
    tabla.insertarCamposGrupo("Clientes","apellidoC","STRING");
    tabla.insertarCamposGrupo("Clientes","telefonoC","INTEGER");

    tabla.insertarCamposGrupo("Trabajadores","nombreT","STRING");
    tabla.insertarCamposGrupo("Trabajadores","apellidoT","STRING");
    tabla.insertarCamposGrupo("Trabajadores","telefonoT","INTEGER");

    tabla.insertarCamposGrupo("Proveedores","nombreP","STRING");
    tabla.insertarCamposGrupo("Proveedores","apellidoP","STRING");
    tabla.insertarCamposGrupo("Proveedores","telefonoP","INTEGER");

    tabla.insertarDatosCampos("Clientes","nombreC","Juana");
    tabla.insertarDatosCampos("Clientes","nombreC","Pedro");
    tabla.insertarDatosCampos("Clientes","nombreC","Julian");
    tabla.insertarDatosCampos("Clientes","nombreC","Marta");
    tabla.insertarDatosCampos("Clientes","nombreC","Carlos");

    tabla.insertarDatosCampos("Clientes","apellidoC","acJuana");
    tabla.insertarDatosCampos("Clientes","apellidoC","acPedro");
    tabla.insertarDatosCampos("Clientes","apellidoC","acJulian");
    tabla.insertarDatosCampos("Clientes","apellidoC","acMarta");
    tabla.insertarDatosCampos("Clientes","apellidoC","acCarlos");

    tabla.insertarDatosCampos("Clientes","telefonoC","12378567");
    tabla.insertarDatosCampos("Clientes","telefonoC","78121456");
    tabla.insertarDatosCampos("Clientes","telefonoC","74821471");
    tabla.insertarDatosCampos("Clientes","telefonoC","78164321");
    tabla.insertarDatosCampos("Clientes","telefonoC","71295304");

    tabla.insertarDatosCampos("Trabajadores","nombreT","tnJuana");
    tabla.insertarDatosCampos("Trabajadores","nombreT","tnPedro");
    tabla.insertarDatosCampos("Trabajadores","nombreT","tnJulian");

    tabla.insertarDatosCampos("Trabajadores","apellidoT","taJuana");
    tabla.insertarDatosCampos("Trabajadores","apellidoT","taPedro");
    tabla.insertarDatosCampos("Trabajadores","apellidoT","taJulian");

    tabla.insertarDatosCampos("Trabajadores","telefonoT","34789654");
    tabla.insertarDatosCampos("Trabajadores","telefonoT","96214782");
    tabla.insertarDatosCampos("Trabajadores","telefonoT","32489135");

    tabla.insertarDatosCampos("Proveedores","nombreP","pnJuana");
    tabla.insertarDatosCampos("Proveedores","nombreP","pnPedro");
    tabla.insertarDatosCampos("Proveedores","nombreP","pnJulian");

    tabla.insertarDatosCampos("Proveedores","apellidoP","paJuana");
    tabla.insertarDatosCampos("Proveedores","apellidoP","paPedro");
    tabla.insertarDatosCampos("Proveedores","apellidoP","paJulian");

    tabla.insertarDatosCampos("Proveedores","telefonoP","74125893");
    tabla.insertarDatosCampos("Proveedores","telefonoP","30215455");
    tabla.insertarDatosCampos("Proveedores","telefonoP","55012366");
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

void opcionExportarContactos(TablaGruposHash &tabla){
    /*
     Esta opción solamente solicitará el nombre del grupo que se desea exportar. Para
esto deberá mostrar el listado de grupos que contiene el sistema.


      */
    //string folderName = "../mi_carpeta";

    tabla.imprimirDatosTabla();

    string nombreG = "";
    cout<<"Escriba el nombre del grupo:"<<endl;
    getline(cin, nombreG);

    int cantidadDatos = tabla.buscarGrupo(nombreG).campos->obtenerCantidadDatos();
    int cantidadDeContactos = tabla.buscarGrupo(nombreG).campos->obtenerCantidadDatosArbol();

    string nombreCarpeta = "../"+nombreG;
    generarCarpeta(nombreCarpeta);
    cout<<"cantidad de contactos: "<<cantidadDeContactos<<endl;
    for(int i=1; i<cantidadDeContactos; i++ ){
        string datosContacto = "";
        string nombreCampo ="";
        string nombreArchivo = "";
        for(int j=1; j<= cantidadDatos; j++){
             nombreCampo = tabla.buscarGrupo(nombreG).campos->obtenerNombreCampo(j);
            datosContacto+= nombreCampo+": ";
            string dato = tabla.buscarGrupo(nombreG).campos->buscarGrupo(nombreCampo).arbol.obtenerDatoNodoArbol(i);
            if(j==1){
                nombreArchivo = nombreG+dato;
            }
            datosContacto+=dato+"\n";

        }


        exportarContacto(nombreCarpeta,nombreArchivo,datosContacto);

    }


}

void opcionGraficaGrupo(TablaGruposHash &tabla){
    tabla.imprimirDatosTabla();

    string nombreG = "";
    cout<<"Escriba el nombre del grupo:"<<endl;
    getline(cin, nombreG);

    ArchivoDOT dot;
    dot.graficarGrupoHash(nombreG,tabla);
}

void opcionGraficarArbolesGrupo(TablaGruposHash &tabla){
    tabla.imprimirDatosTabla();

    string nombreG = "";
    cout<<"Escriba el nombre del grupo:"<<endl;
    getline(cin, nombreG);

    ArchivoDOT dot;
    dot.graficarArbolesGrupo(nombreG,tabla);
};
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
        cout<<"      5. Estado actual de toda la estructura completa"<<endl;
        cout<<"      6. Estado actual de cada una de las estructuras por separado"<<endl;
        cout<<"      7. Estado actual de los datos de un grupo"<<endl;
        cout<<"-->Exportacion de contactos"<<endl;
        cout<<"      8. Exportar Contactos"<<endl;
        cout<<"-->Cerrar Programa"<<endl;
        cout<<"      9. Salir"<<endl;
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
                ArchivoDOT dot;
                dot.graficarTablaHashGlobal(tabla);
                break;
            case 6:
                opcionGraficaGrupo(tabla);
                break;
            case 7:
                opcionGraficarArbolesGrupo(tabla);
                break;
            case 8:
                opcionExportarContactos(tabla);
                break;


        }

    }while(opcion != 9);
    //tabla.imprimirDatosTabla();
    //tabla.buscarGrupo("Clientes").campos->buscarGrupo("nombre").arbol.imprimirInOrden();
    //tabla.buscarGrupo("Clientes").campos->buscarGrupo("telefono").arbol.imprimirInOrden();

     return 0;

}
