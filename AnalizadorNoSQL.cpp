#include "AnalizadorNoSQL.h"
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>

AnalizadorNoSQL::AnalizadorNoSQL(MotorDatosNoSQL& motor) : motor(motor) {}

void AnalizadorNoSQL::analizar(const std::string& comando){

    std::istringstream flujo(comando); //flujo para dividir el comando en palabras clave 
    std::string keyword; //palabra clave para identificar el comando
    flujo >> keyword; 

    // Convierte la palabra clave a minúsculas para facilitar la comparación
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    // Ejecuta la acción correspondiente según la palabra clave
    if (keyword == "INSERT_FIELD") analizarInsertField(flujo);
    else if (keyword == "UPDATE_FIELD") analizarUpdateField(flujo);
    else if (keyword == "GET_FIELD") analizarGetField(flujo);
    else if (keyword == "DELETE_FIELD") analizarDeleteField(flujo);
    else if (keyword == "LIST_DOCUMENT") analizarListDocument(flujo);
    else if (keyword == "LIST_ALL") analizarListAll(flujo);
    else std::cout << "Comando no reconocido\n";

}

void AnalizadorNoSQL::analizarInsertField(std::istringstream& flujo) {
    std::string comando, id_document, field_key, field_value;
    flujo >> comando >> id_document >> field_key >> field_value;

    std::getline(flujo, field_value);


    id_document = clean(id_document);
    field_key = clean(field_key);
    field_value = clean(field_value);

    motor.insertField(id_document, field_key, field_value);
}

void AnalizadorNoSQL::analizarGetField(std::istringstream& flujo) {
    std::string comando, id_document, field_key;
    flujo >> comando >> id_document >> field_key;

    id_document = clean(id_document);
    field_key = clean(field_key);

    motor.getField(id_document, field_key);
}







std::string AnalizadorNoSQL::clean(const std::string& cadena) {
    if (cadena.front() == '"' && cadena.back() == '"') {
        return cadena.substr(1, cadena.size() - 2);
    }
    return cadena;
}