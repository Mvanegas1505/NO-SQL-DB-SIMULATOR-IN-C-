#include <iostream>
#include <unordered_map>
#include <string>
#include "MotorDatosNoSQL.h" 
#include "AnalizadorNoSQL.h" 
int main() {
    // Crea una instancia del motor de datos NoSQL
    MotorDatosNoSQL db;

    // Crea una instancia del analizador, pasándole como referencia el motor de datos
    AnalizadorNoSQL parser(db);

    std::string comando; // Variable para almacenar el comando ingresado por el usuario

    // Bucle infinito para aceptar comandos hasta que el usuario escriba "exit"
    while (true) {
        std::cout << "NoSQL> ";               // Muestra un prompt indicando que está listo para un comando
        std::getline(std::cin, comando);     // Lee el comando completo ingresado por el usuario
        if (comando == "exit" || comando == "EXIT") break;        // Si el usuario escribe "exit", termina el programa
        parser.analizar(comando);            // Pasa el comando al analizador para su procesamiento
    }

    return 0; // Indica que el programa terminó exitosamente
}
