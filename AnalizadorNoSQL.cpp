#include "AnalizadorNoSQL.h"
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>

// Constructor: Inicializa el analizador con una referencia al motor de datos
AnalizadorNoSQL::AnalizadorNoSQL(MotorDatosNoSQL& motor) : motor(motor) {}

// Método principal que recibe un comando en formato de string
void AnalizadorNoSQL::analizar(const std::string& comando) {
    std::istringstream flujo(comando); // Divide el comando en palabras clave
    std::string keyword; // Palabra clave para identificar qué acción ejecutar
    flujo >> keyword; 

    // Convierte la palabra clave a minúsculas para facilitar la comparación
    std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    // Compara la palabra clave y ejecuta la función correspondiente
    if (keyword == "insert_field") analizarInsertField(flujo);
    else if (keyword == "update_field") analizarUpdateField(flujo);
    else if (keyword == "get_field") analizarGetField(flujo);
    else if (keyword == "delete_field") analizarDeleteField(flujo);
    else if (keyword == "list_document") analizarListDocument(flujo);
    else if (keyword == "list_all") analizarListAll(flujo);
    else std::cout << "Comando no reconocido\n"; // Mensaje si el comando es inválido
}

// Analiza el comando INSERT_FIELD
void AnalizadorNoSQL::analizarInsertField(std::istringstream& flujo) {
    std::string id_document, field_key, field_value;

    // Usa std::quoted para leer cadenas con comillas automáticamente
    flujo >> std::quoted(id_document) >> std::quoted(field_key) >> std::quoted(field_value);

    // Llama al motor para insertar el campo en el documento especificado
    motor.insertField(id_document, field_key, field_value);
}

// Analiza el comando GET_FIELD
void AnalizadorNoSQL::analizarGetField(std::istringstream& flujo) {
    std::string id_document, field_key;
    flujo >> id_document >> field_key; // Lee el ID del documento y el campo

    // Limpia posibles comillas alrededor de las cadenas
    id_document = clean(id_document);
    field_key = clean(field_key);

    // Llama al motor para obtener el valor del campo
    motor.getField(id_document, field_key);
}

// Analiza el comando UPDATE_FIELD
void AnalizadorNoSQL::analizarUpdateField(std::istringstream& flujo) {
    std::string id_document, field_key, new_value;

    flujo >> id_document >> field_key; // Lee el ID del documento y el campo a actualizar
    std::getline(flujo, new_value);   // Lee el nuevo valor del campo (puede contener espacios)

    // Limpia posibles comillas alrededor de las cadenas
    id_document = clean(id_document);
    field_key = clean(field_key);
    new_value = clean(new_value);

    // Llama al motor para actualizar el campo
    motor.updateField(id_document, field_key, new_value);
}

// Analiza el comando DELETE_FIELD
void AnalizadorNoSQL::analizarDeleteField(std::istringstream& flujo) {
    std::string id_document, field_key;
    flujo >> id_document >> field_key; // Lee el ID del documento y el campo a eliminar

    // Limpia posibles comillas alrededor de las cadenas
    id_document = clean(id_document);
    field_key = clean(field_key);

    // Llama al motor para eliminar el campo
    motor.deleteField(id_document, field_key);

    // Mensaje de confirmación
    std::cout << "Campo '" << field_key << "' del documento '" << id_document << "' eliminado.\n";
}

// Analiza el comando LIST_DOCUMENT
void AnalizadorNoSQL::analizarListDocument(std::istringstream& flujo) {
    std::string id_document;
    flujo >> id_document; // Lee el ID del documento a listar

    // Limpia posibles comillas alrededor de la cadena
    id_document = clean(id_document);

    // Llama al motor para listar los campos del documento
    motor.listDocument(id_document);
}

// Analiza el comando LIST_ALL
void AnalizadorNoSQL::analizarListAll(std::istringstream& flujo) {
    // No necesita parámetros adicionales
    motor.listAll(); // Llama al motor para listar todos los documentos
}

// Limpia una cadena eliminando comillas al inicio y al final
std::string AnalizadorNoSQL::clean(const std::string& cadena) {
    if (!cadena.empty() && cadena.front() == '"' && cadena.back() == '"') {
        // Devuelve la cadena sin las comillas
        return cadena.substr(1, cadena.size() - 2);
    }
    return cadena; // Si no tiene comillas, devuelve la cadena original
}
