//
// Created by rudyo on 30/03/2024.
//

#include "ArchivoLog.h"
string getCurrentDateTime(){
    // Obtener el tiempo actual
    auto now = std::chrono::system_clock::now();

    // Convertir el tiempo actual a un tiempo en formato de tiempo c
    time_t time = chrono::system_clock::to_time_t(now);

    // Convertir el tiempo c a una cadena de caracteres con el formato deseado
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));

    string horaFecha = "["+string(buffer)+"] ";
    return horaFecha;
}

void crearArchivoLog(){
    string filePath ="../gestionLog.log";
    ofstream outputFile(filePath);
    if (outputFile.is_open()) {
        string dateTime =getCurrentDateTime();
        outputFile <<dateTime<<" Create:Creacion archivo log" << endl;
        outputFile.close();
        cout << "Archivo log creado correctamente." << endl;
    } else {
        cout << "Error al crear el archivo de texto." << endl;

    }
}

void nuevaEntradaLog(string accion, string info){
    string filePath ="../gestionLog.log";
    ofstream outputFile(filePath, ios::app); // Abrir el archivo en modo de escritura para agregar al final

    if (outputFile.is_open()) {
        // Obtener la fecha y hora actual
        string dateTime = getCurrentDateTime();

        // Insertar datos en el archivo
        outputFile << dateTime << accion<<": "<<info<<endl;

        // Cerrar el archivo
        outputFile.close();

    } else {
        cout << "Error al abrir el archivo de log." << endl;
    }
}