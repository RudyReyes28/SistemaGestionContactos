//
// Created by rudyo on 24/03/2024.
//

#include "ArchivoDOT.h"

void ArchivoDOT::generarArchivoDOT(NodoArbol *raiz, ofstream &archivoDot) {
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

void ArchivoDOT::obtenerArchivoDOT(NodoArbol *raiz) {
    ofstream archivoDot("../graph.dot"); // Crea un archivo DOT
    if (!archivoDot.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    }else {
        archivoDot << "digraph ArbolAVL {\n";
        archivoDot << "node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black]" << ";\n";
        generarArchivoDOT(raiz, archivoDot);
        archivoDot << "}\n";

        archivoDot.close();

        // Llamada al comando dot para generar la imagen del árbol
        system("dot -Tpng ../graph.dot -o ../graph.png");
        cout << "Grafico generado correctamente." << endl;
    }
}

void ArchivoDOT::generarDOTCampos(TablaCampoHash tabla) {
    cout<<"Entrando Correctamente"<<endl;
    ofstream archivoDot("../graph.dot"); // Crea un archivo DOT
    if (!archivoDot.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    }else {
        archivoDot << "digraph ArbolAVL {\n";
        archivoDot << "node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black]" << ";\n";
        CampoHash* campos = tabla.obtenerTabla();
        int tamano = tamano;
        for(int i=0; i< tabla.getTamanoTabla(); i++){
            if (!campos[i].nombreCampo.empty()) {
                cout<<"Entrando al metodo de archivosDOT"<<endl;
                cout<<campos[i].nombreCampo<<endl;
                NodoArbol *raiz = campos[i].arbol.getArbol();
                generarArchivoDOT(raiz,archivoDot);
            }
        }
        archivoDot << "}\n";

        archivoDot.close();

        // Llamada al comando dot para generar la imagen del árbol
        system("dot -Tpng ../graph.dot -o ../graph.png");
        cout << "Grafico generado correctamente." << endl;
    }

    cout<<"metodo completado"<<endl;
}
