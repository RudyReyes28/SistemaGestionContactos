#include <iostream>
#include "tablaHashGrupos/TablaGruposHash.h"
#include "ArbolesAvl//ArbolAVL.h"
#include <fstream>
using namespace std;

void generarArchivoDOT(NodoArbol* raiz, ofstream& archivoDot) {

    if (raiz) {
        archivoDot << raiz->dato << ";\n";
        if (raiz->izq) {
            archivoDot << raiz->dato << " -> " << raiz->izq->dato << ";\n";
            generarArchivoDOT(raiz->izq, archivoDot);
        }
        if (raiz->der) {
            archivoDot << raiz->dato << " -> " << raiz->der->dato << ";\n";
            generarArchivoDOT(raiz->der, archivoDot);
        }
    }
}

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
    ArbolAVL arbol;
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

    raiz = arbol.getArbol();
    ofstream archivoDot("../graph.dot"); // Crea un archivo DOT
    if (!archivoDot.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }
    archivoDot << "digraph ArbolAVL {\n";
    archivoDot<<"node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black]"<<";\n";
    generarArchivoDOT(raiz, archivoDot);

    archivoDot << "}\n";
    //archivoDot<<code<<endl;
    archivoDot.close();

    // Llamada al comando dot para generar la imagen del árbol
    //system("dot -Tpng arbol.dot -o arbol.png");
    system("dot -Tpng ../graph.dot -o ../graph.png");
    cout << "Grafico generado correctamente." << endl;
}
