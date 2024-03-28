//
// Created by rudyo on 27/03/2024.
//

#ifndef GESTIONDECONTACTOS_EXPORTARCONTACTO_H
#define GESTIONDECONTACTOS_EXPORTARCONTACTO_H
#include <iostream>
#include<string>
#include <fstream>
#include <filesystem>

#ifdef _WIN32
#include <direct.h> // Para Windows
#define mkdir _mkdir
#else
#include <sys/stat.h> // Para sistemas basados en Unix
#endif

using namespace std;
namespace fs = std::filesystem;
void generarCarpeta(string nombreCarpeta);

void exportarContacto(string nombreCarpeta, string nombreArchivo, string contacto);
#endif //GESTIONDECONTACTOS_EXPORTARCONTACTO_H
