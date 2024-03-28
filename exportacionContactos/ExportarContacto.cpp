//
// Created by rudyo on 27/03/2024.
//

#include "ExportarContacto.h"

void generarCarpeta(string nombreCarpeta){
    //string folderName = "../mi_carpeta";
    string folderName = nombreCarpeta;
    if (fs::exists(folderName) && fs::is_directory(folderName)) {
        cout << "La carpeta ya existe." << endl;
    } else {
        cout << "La carpeta no existe." << endl;
        //Creamos la carpeta.
        #ifdef _WIN32
            int folderCreated = mkdir(folderName.c_str());
        #else
            int folderCreated = mkdir(folderName.c_str(), 0777); // Permisos en sistemas Unix
        #endif

        if (folderCreated == 0) {
            cout << "Carpeta creada correctamente." << endl;
        } else {
            cout << "Error al crear la carpeta. Es posible que ya exista" << endl;
        }
    }
}

void exportarContacto(string nombreCarpeta, string nombreArchivo, string contacto){
    string filePath = nombreCarpeta +"/"+nombreArchivo+".txt";
    ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        outputFile <<contacto << endl;
        outputFile.close();
        cout << "Archivo de texto creado correctamente." << endl;
    } else {
        cout << "Error al crear el archivo de texto." << endl;

    }
}