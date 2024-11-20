#ifndef ANALIZADOR_NOSQL_H
#define ANALIZADOR_NOSQL_H

#include "MotorDatosNoSQL.h" // Tu motor NoSQL
#include <string>
#include <sstream>
#include <iostream>

class AnalizadorNoSQL {
public:
    AnalizadorNoSQL(MotorDatosNoSQL& motor);

    // Analiza un comando recibido y ejecuta la acción correspondiente
    void analizar(const std::string& comando);

private:
    MotorDatosNoSQL& motor;  // Referencia al motor NoSQL

    // Métodos para procesar cada tipo de comando
    void analizarInsertField(std::istringstream& flujo);
    void analizarUpdateField(std::istringstream& flujo);
    void analizarGetField(std::istringstream& flujo);
    void analizarDeleteField(std::istringstream& flujo);
    void analizarListDocument(std::istringstream& flujo);
    void analizarListAll(std::istringstream& flujo);

    // Función auxiliar para limpiar comillas de los argumentos
    std::string clean(const std::string& cadena);
};

#endif