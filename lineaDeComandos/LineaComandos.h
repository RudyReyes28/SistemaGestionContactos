//
// Created by rudyo on 25/03/2024.
//

#ifndef GESTIONDECONTACTOS_LINEACOMANDOS_H
#define GESTIONDECONTACTOS_LINEACOMANDOS_H
#include <vector>
#include <sstream>
#include <string>
using namespace std;
vector<pair<string,string>> creacionDeGruposComando(string comando);
vector<string> insercionContactosComando(string comando);
vector<string> busquedaContactosComando(string comando);
#endif //GESTIONDECONTACTOS_LINEACOMANDOS_H
