cmake_minimum_required(VERSION 3.27)
project(GestionDeContactos)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestionDeContactos main.cpp
        tablaHashGrupos/GrupoHash.cpp
        tablaHashGrupos/GrupoHash.h
        tablaHashGrupos/TablaGruposHash.cpp
        tablaHashGrupos/TablaGruposHash.h
        ArbolesAvl/NodoArbol.cpp
        ArbolesAvl/NodoArbol.h
        ArbolesAvl/ArbolAVL.cpp
        ArbolesAvl/ArbolAVL.h
        generarArchivos/ArchivoDOT.cpp
        generarArchivos/ArchivoDOT.h
        tablaHashCampos/CampoHash.cpp
        tablaHashCampos/CampoHash.h
        tablaHashCampos/TablaCampoHash.cpp
        tablaHashCampos/TablaCampoHash.h
        lineaDeComandos/LineaComandos.cpp
        lineaDeComandos/LineaComandos.h
        exportacionContactos/ExportarContacto.cpp
        exportacionContactos/ExportarContacto.h
        exportacionContactos/ArchivoLog.cpp
        exportacionContactos/ArchivoLog.h)
