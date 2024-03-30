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

void ArchivoDOT::graficarArbolesGrupo(string nombreG,TablaGruposHash &tabla) {
    ofstream archivoDot("../arbolesGrupo.dot"); // Crea un archivo DOT
    if (!archivoDot.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    }else {
        archivoDot << "digraph ArbolAVL {\n";
        archivoDot << "node [shape=circle, style=filled, fillcolor=lightblue, fontcolor=black]" << ";\n";
        CampoHash* campos = tabla.buscarGrupo(nombreG).campos->obtenerTabla();
        int tamano = tabla.buscarGrupo(nombreG).campos->getTamanoTabla();
        for(int i=0; i< tamano; i++){
            if (!campos[i].nombreCampo.empty()) {
                NodoArbol *raiz = campos[i].arbol.getArbol();
                archivoDot<<campos[i].nombreCampo<<" ->"<<raiz->dato<<";\n";
                generarArchivoDOT(raiz,archivoDot);
            }
        }
        archivoDot << "}\n";

        archivoDot.close();

        // Llamada al comando dot para generar la imagen del árbol
        system("dot -Tpng ../arbolesGrupo.dot -o ../arbolesGrupo.png");
        cout << "Grafico generado correctamente." << endl;
    }
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

            //AGREGRAMOS LOS ARBOLES A LA GRAFICA

            for(int j=0; j<tamanoTablaC; j++){
                if(!tablaCampo[j].nombreCampo.empty()){
                    archivoDot<<"        <TR><TD PORT=\""<<"arbol"<<j<<"\">"<<reinterpret_cast<void*>(&tablaCampo[j].arbol)<<"</TD></TR>\n";
                }else{
                    archivoDot<<"        <TR><TD PORT=\""<<"null"<<j <<"\">"<<"     "<<"</TD></TR>\n";
                }
            }

            archivoDot<<"    </TABLE>>];\n";

            //CONECTAMOS LOS CAMPOS CON LOS ARBOLES
            for(int j=0; j<tamanoTablaC; j++){
                if(!tablaCampo[j].nombreCampo.empty()){
                    archivoDot<<"campo"<<nuevaTabla[i].nombreGrupo<<":"<<tablaCampo[j].nombreCampo<<" ->"<< "arbol"<<nuevaTabla[i].nombreGrupo<<":"<<"arbol"<<j <<";\n";
                }
            }

            //AQUI PODRIAMOS CONECTAR LA GRAFICA CON LOS ARBOLES

            for(int j=0; j< tamanoTablaC; j++){
                if (!tablaCampo[j].nombreCampo.empty()) {

                    NodoArbol *raiz = tablaCampo[j].arbol.getArbol();
                    archivoDot<<"arbol"<<nuevaTabla[i].nombreGrupo<<":"<<"arbol"<<j <<" ->"<<raiz->dato<<";\n";
                    generarArchivoDOT(raiz,archivoDot);
                }
            }

        }

    }
    for(int i = 0; i < tamanoActual; ++i){
        if (!nuevaTabla[i].nombreGrupo.empty()) {
            archivoDot<<"valores:"<<"tablac"<<i <<" -> campo"<<nuevaTabla[i].nombreGrupo<<":"<<"campos"<<i <<";\n";
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

void ArchivoDOT::graficarTablaHashGlobal(TablaGruposHash &tabla) {

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
void ArchivoDOT::archivoDOTCamposGrupo(ofstream& archivoDot, string nombre, TablaGruposHash &tabla) {
    int tamanoActual = tabla.obtenerTamanoActual();
    GrupoHash* nuevaTabla = tabla.obtenerTabla();
    for(int i = 0; i < tamanoActual; ++i){
        if (!nuevaTabla[i].nombreGrupo.empty()) {
            if(nuevaTabla[i].nombreGrupo == nombre){
                archivoDot<<"    grupo"<<nombre<< "[label=<\n";
                archivoDot<<"    <TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n";
                archivoDot<<"        <TR><TD PORT=\"grupo"<<"\""<<">"<<nombre<<"</TD></TR>\n";
                archivoDot<<"    </TABLE>>];\n";

                archivoDot<<"    campo"<<nombre<< "[label=<\n";
                archivoDot<<"    <TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n";
                archivoDot<<"        <TR><TD PORT=\"campos"<<"\""<<">CAMPOS</TD></TR>\n";
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

                //AGREGRAMOS LOS ARBOLES A LA GRAFICA

                for(int j=0; j<tamanoTablaC; j++){
                    if(!tablaCampo[j].nombreCampo.empty()){
                        archivoDot<<"        <TR><TD PORT=\""<<"arbol"<<j<<"\">"<<reinterpret_cast<void*>(&tablaCampo[j].arbol)<<"</TD></TR>\n";
                    }else{
                        archivoDot<<"        <TR><TD PORT=\""<<"null"<<j <<"\">"<<"     "<<"</TD></TR>\n";
                    }
                }

                archivoDot<<"    </TABLE>>];\n";

                //CONECTAMOS LOS CAMPOS CON LOS ARBOLES
                for(int j=0; j<tamanoTablaC; j++){
                    if(!tablaCampo[j].nombreCampo.empty()){
                        archivoDot<<"campo"<<nuevaTabla[i].nombreGrupo<<":"<<tablaCampo[j].nombreCampo<<" ->"<< "arbol"<<nuevaTabla[i].nombreGrupo<<":"<<"arbol"<<j <<";\n";
                    }
                }

                archivoDot<<"grupo"<<nombre<<":"<<"grupo -> campo"<<nombre<<": campos;\n";
            }


        }

    }

}

void ArchivoDOT::graficarGrupoHash(string nombre, TablaGruposHash &tabla) {
    ofstream archivoDot("../grupoHash.dot"); // Crea un archivo DOT
    if (!archivoDot.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    }else {
        archivoDot << "digraph tablaHash {\n";
        archivoDot<<"node [shape=plaintext, fontname=Arial];\n";

        archivoDOTCamposGrupo(archivoDot,nombre,tabla);

        archivoDot << "}\n";

        archivoDot.close();

        // Llamada al comando dot para generar la imagen del árbol
        system("dot -Tpng ../grupoHash.dot -o ../grupoHash.png");
        cout << "Grafico generado correctamente." << endl;
    }

}




