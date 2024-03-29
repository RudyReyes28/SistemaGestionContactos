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

void ArchivoDOT::generarDOTCampos(TablaCampoHash &tabla) {
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

void ArchivoDOT::archivoDOTTablaCampos(ofstream &archivoDot, TablaGruposHash &tabla) {
    int tamanoActual = tabla.obtenerTamanoActual();
    GrupoHash* nuevaTabla = tabla.obtenerTabla();
    for(int i = 0; i < tamanoActual; ++i){
        if (!nuevaTabla[i].nombreGrupo.empty()) {
            archivoDot<<"    campo"<<nuevaTabla[i].nombreGrupo<< "[label=<\n";
            archivoDot<<"    <TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n";
            archivoDot<<"        <TR><TD PORT=\"campos"<<i<<"\""<<">CAMPOS</TD></TR>\n";
            CampoHash* tablaCampo = tabla.buscarGrupo(nuevaTabla[i].nombreGrupo).campos->obtenerTabla();
            int tamanoTablaC = tabla.buscarGrupo(nuevaTabla[i].nombreGrupo).campos->getTamanoTabla();

            for(int j=0; j<tamanoTablaC; j++){
                if(!tablaCampo[j].nombreCampo.empty()){
                    archivoDot<<"        <TR><TD PORT=\""<<tablaCampo[j].nombreCampo<<"\">"<<tablaCampo[j].nombreCampo<<"</TD></TR>\n";
                }
            }
            archivoDot<<"    </TABLE>>];\n";

            archivoDot<<"    arbol"<<nuevaTabla[i].nombreGrupo<<" [label=<\n";
            archivoDot<<"    <TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n";
            archivoDot<<"        <TR><TD PORT=\"arbol\">Arboles</TD></TR>\n";

            for(int j=0; j<tamanoTablaC; j++){
                if(!tablaCampo[j].nombreCampo.empty()){
                    archivoDot<<"        <TR><TD PORT=\""<<"arbol"<<j<<"\">"<<reinterpret_cast<void*>(&tablaCampo[j].arbol)<<"</TD></TR>\n";
                }else{
                    archivoDot<<"        <TR><TD PORT=\""<<"null"<<j <<"\">"<<"     "<<"</TD></TR>\n";
                }
            }

            archivoDot<<"    </TABLE>>];\n";

            for(int j=0; j<tamanoTablaC; j++){
                if(!tablaCampo[j].nombreCampo.empty()){
                    archivoDot<<"campo"<<nuevaTabla[i].nombreGrupo<<":"<<tablaCampo[j].nombreCampo<<" ->"<< "arbol"<<nuevaTabla[i].nombreGrupo<<":"<<"arbol"<<j <<";\n";
                }
            }

        }

    }
    for(int i = 0; i < tamanoActual; ++i){
        if (!nuevaTabla[i].nombreGrupo.empty()) {
            archivoDot<<"valores:"<<"tablac"<<i <<" -> ""campo"<<nuevaTabla[i].nombreGrupo<<":"<<"campos"<<i <<";\n";
        }
    }

}
void ArchivoDOT::archivoDOTTablaHashGlobal(ofstream& archivoDot, TablaGruposHash &tabla){
    archivoDot<<"    entrada [label=<\n";
    archivoDot<<"    <TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n";
    archivoDot<<"        <TR><TD PORT=\"entrada\">ENTRADA</TD></TR>\n";
    // "        <TR><TD PORT=\"llave2\">entrada2</TD><TD PORT=\"val2\">grupo2</TD></TR>"
    int tamanoActual = tabla.obtenerTamanoActual();
    GrupoHash* nuevaTabla = tabla.obtenerTabla();
    for(int i = 0; i < tamanoActual; ++i){
        if (!nuevaTabla[i].nombreGrupo.empty()) {
            archivoDot<<"        <TR><TD PORT=\""<<nuevaTabla[i].nombreGrupo<<"\">"<<nuevaTabla[i].nombreGrupo<<"</TD></TR>\n";
        }
    }
    archivoDot<<"    </TABLE>>];\n";

    archivoDot<<"    valores [label=<\n";
    archivoDot<<"    <TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n";
    archivoDot<<"        <TR><TD PORT=\"val1\">GRUPOS</TD></TR>\n";

    for(int i = 0; i < tamanoActual; ++i){
        if (!nuevaTabla[i].nombreGrupo.empty()) {
            archivoDot<<"        <TR><TD PORT=\""<<"tablac"<<i<<"\">"<<&nuevaTabla[i].campos<<"</TD></TR>\n";
        }else{
            archivoDot<<"        <TR><TD PORT=\""<<"null"<<i <<"\">"<<"     "<<"</TD></TR>\n";
        }
    }
    archivoDot<<"    </TABLE>>];\n";




    //enlaces
    for(int i = 0; i < tamanoActual; ++i){
        if (!nuevaTabla[i].nombreGrupo.empty()) {
            archivoDot<<"entrada:"<<nuevaTabla[i].nombreGrupo<<" -> valores:"<<"tablac"<<i <<";\n";
        }
    }

    //aqui se deberia de crear las otras tablas
    archivoDOTTablaCampos(archivoDot,tabla);

}

void ArchivoDOT::graficarTablaHash(TablaGruposHash &tabla) {

    ofstream archivoDot("../tablaHash.dot"); // Crea un archivo DOT
    if (!archivoDot.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    }else {
        archivoDot << "digraph tablaHash {\n";
        archivoDot<<"node [shape=plaintext, fontname=Arial];\n";

        archivoDOTTablaHashGlobal(archivoDot,tabla);

        archivoDot << "}\n";

        archivoDot.close();

        // Llamada al comando dot para generar la imagen del árbol
        system("dot -Tpng ../tablaHash.dot -o ../tablaHash.png");
        cout << "Grafico generado correctamente." << endl;
    }

}


