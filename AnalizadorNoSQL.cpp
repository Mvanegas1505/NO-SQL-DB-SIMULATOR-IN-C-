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
    if (keyword == "insert_field") analizarInsertField(flujo);
    else if (keyword == "update_field") analizarUpdateField(flujo);
    else if (keyword == "get_field") analizarGetField(flujo);
    else if (keyword == "delete_field") analizarDeleteField(flujo);
    else if (keyword == "list_document") analizarListDocument(flujo);
    else if (keyword == "list_all") analizarListAll(flujo);
    else std::cout << "Comando no reconocido\n";

}

void AnalizadorNoSQL::analizarInsertField(std::istringstream& flujo) {
    std::string id_document, field_key, field_value;
    flujo >> id_document >> field_key >> field_value;

    id_document = clean(id_document);
    field_key = clean(field_key);
    field_value = clean(field_value);

    motor.insertField(id_document, field_key, field_value);
}

void AnalizadorNoSQL::analizarGetField(std::istringstream& flujo) {
    std::string id_document, field_key;
    flujo >> id_document >> field_key;

    id_document = clean(id_document);
    field_key = clean(field_key);

    motor.getField(id_document, field_key);
}

void AnalizadorNoSQL::analizarUpdateField(std::istringstream& flujo) {
    std::string id_document, field_key, new_value;

    flujo >> id_document >> field_key;
    std::getline(flujo, new_value);

    id_document = clean(id_document);
    field_key = clean(field_key);
    new_value = clean(new_value);

    motor.updateField(id_document, field_key, new_value);
}

void AnalizadorNoSQL::analizarDeleteField(std::istringstream& flujo) {
    std::string comando, id_document, field_key;
    flujo >> comando >> id_document >> field_key;

    id_document = clean(id_document);
    field_key = clean(field_key);

    motor.deleteField(id_document, field_key);

    std::cout << "Campo '" << field_key << "' del documento '" << id_document << "' eliminado.\n";
}

void AnalizadorNoSQL::analizarListDocument(std::istringstream& flujo) {

    std::string id_document;
    flujo >> id_document;

    id_document = clean(id_document);

    motor.listDocument(id_document);
}

void AnalizadorNoSQL::analizarListAll(std::istringstream& flujo) {

    motor.listAll();
}







std::string AnalizadorNoSQL::clean(const std::string& cadena) {
    if (!cadena.empty() && cadena.front() == '"' && cadena.back() == '"') {
        return cadena.substr(1, cadena.size() - 2);
    }
    return cadena;
}
