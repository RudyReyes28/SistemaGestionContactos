//
// Created by rudyo on 30/03/2024.
//

#ifndef GESTIONDECONTACTOS_ARCHIVOLOG_H
#define GESTIONDECONTACTOS_ARCHIVOLOG_H
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
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
string getCurrentDateTime();
void crearArchivoLog();
void nuevaEntradaLog(string accion, string info);

#endif //GESTIONDECONTACTOS_ARCHIVOLOG_H
