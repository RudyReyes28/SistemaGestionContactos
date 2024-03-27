//
// Created by rudyo on 25/03/2024.
//

#include "LineaComandos.h"
vector<pair<string,string>> creacionDeGruposComando(string comando){
    stringstream ss(comando);

    // Leer el comando palabra por palabra
    string palabra;
    vector<string> palabras;
    while (ss >> palabra) {
        palabras.push_back(palabra);
    }


    // Analizar las palabras
    string nombreGrupo;
    vector<pair<string,string>> campos;
    for (size_t i = 0; i < palabras.size(); ++i) {
        if (palabras[i] == "ADD" && palabras[i + 1] == "NEW-GROUP") {
            //nombreGrupo = palabras[i + 2];
            campos.emplace_back(palabras[i + 2], "NombreGrupo");
            // Saltar hasta el inicio de los campos
            i += 4; // "ADD NEW-GROUP nombre FIELDS ("
            // Analizar los campos
            while (palabras[i] != ");" && i< palabras.size()) {
                string campo = palabras[i++];
                string tipoDato = palabras[i++];
                // Eliminar la ',' al final si existe
                if (tipoDato.back() == ',' || tipoDato.back() == ';') {
                    tipoDato.pop_back();
                }

                if(tipoDato.back() == ')'){
                    tipoDato.pop_back();
                }

                if(campo.front() == '('){
                    campo.erase(campo.begin());
                }
                campos.emplace_back(campo, tipoDato);
            }
        }
    }

    return campos;
}

vector<string> insercionContactosComando(string comando){
    stringstream ss(comando);

    // Leer el comando palabra por palabra
    string palabra;
    vector<string> palabras;
    while (ss >> palabra) {
        palabras.push_back(palabra);
    }


    // Analizar las palabras
    vector<string> contactos;
    for (size_t i = 0; i < palabras.size(); ++i) {
        if (palabras[i] == "ADD" && palabras[i + 1] == "CONTACT" && palabras[i+2]=="IN") {
            contactos.emplace_back(palabras[i + 3]);
            // Saltar hasta el inicio de los campos
            i += 5; // "ADD NEW-GROUP nombre FIELDS ("
            // Analizar los campos
            while (palabras[i] != ");" && i< palabras.size()) {
                string contacto = palabras[i++];
                // Eliminar la ',' al final si existe
                if (contacto.back() == ',' || contacto.back() == ';') {
                    contacto.pop_back();
                }

                if(contacto.back() == ')'){
                    contacto.pop_back();
                }

                if(contacto.front() == '('){
                    contacto.erase(contacto.begin());
                }


                contactos.emplace_back(contacto);
            }
        }
    }

    return contactos;
}

vector<string> busquedaContactosComando(string comando){
    stringstream ss(comando);

    // Leer el comando palabra por palabra
    string palabra;
    vector<string> palabras;
    while (ss >> palabra) {
        palabras.push_back(palabra);
    }


    // Analizar las palabras
    vector<string> busqueda;
    for (size_t i = 0; i < palabras.size(); ++i) {
        if (palabras[i] == "FIND" && palabras[i + 1] == "CONTACT" && palabras[i+2]=="IN") {
            busqueda.emplace_back(palabras[i + 3]);
            // Saltar hasta el inicio de los campos
            i += 5; // "ADD NEW-GROUP nombre FIELDS ("

            string datosBusqueda = palabras[i];
            size_t pos = datosBusqueda.find('=');

            // Verificar si el igual fue encontrado
            if (pos != string::npos) {
                // Extraer la parte antes del igual
               string parte1 = datosBusqueda.substr(0, pos);
                busqueda.emplace_back(parte1);
                // Extraer la parte después del igual
               string parte2 = datosBusqueda.substr(pos + 1);
                if(parte2.back() == ';'){
                    parte2.pop_back();
                }
                busqueda.emplace_back(parte2);
            }


        }
    }

    return busqueda;
}
/*
 string comando = "ADD NEW-GROUP friends FIELDS (nombre STRING, apodo STRING, celular INTEGER, cumpleanios DATE, apellido STRING, correo STRING);";

    vector<pair<string,string>> campos = creacionDeGruposComando(comando);

    // Imprimir los resultados
    for (const auto& campo : campos) {
        cout << "Campo: " << campo.first << " Tipo de dato: " << campo.second <<endl;
    }

    string contacto = "ADD CONTACT IN amigos FIELDS (Pedro, Alvarez, 12345678, 02-05-1998, marta, A, carla);";
    vector<string> contactos = insercionContactosComando(contacto);

    string buscar = "FIND CONTACT IN clientes CONTACT-FIELD cumpleanios=2020-21-10;";
    vector<string> busqueda = busquedaContactosComando(buscar);
    for(int i=0; i<busqueda.size(); i++){
        cout<<"dato: "<<busqueda[i]<<endl;
    }

 */