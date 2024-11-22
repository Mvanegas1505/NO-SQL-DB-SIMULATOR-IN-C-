#include "MotorDatosNoSQL.h"  
#include <iostream>

// Función para insertar un campo en un documento
void MotorDatosNoSQL::insertField(const std::string& id_document, const std::string& field_key, const std::string& field_value) {
    // Obtiene (o crea) el documento con el id especificado
    auto& document = tablaDocumentos[id_document];

    // Verifica si el campo ya existe en el documento
    if (document.find(field_key) != document.end()) {
        std::cout << "Error: El campo ya existe en el documento." << std::endl;
        return; // Termina si el campo ya existe
    }

    // Inserta el campo y su valor en el documento
    document[field_key] = field_value;
    std::cout << "Inserts in field " << field_key << " value " << field_value << " into document " << id_document << std::endl;
}

// Función para actualizar el valor de un campo en un documento
void MotorDatosNoSQL::updateField(const std::string& id_document, const std::string& field_key, const std::string& new_value) {
    // Busca el documento en la tabla
    auto it = tablaDocumentos.find(id_document);

    // Verifica si el documento o el campo no existen
    if (it == tablaDocumentos.end() || it->second.find(field_key) == it->second.end()) {
        std::cout << "Error: Documento o campo no encontrado." << std::endl;
        return; // Termina si no encuentra el documento o el campo
    }

    // Actualiza el valor del campo
    it->second[field_key] = new_value;
    std::cout << "Campo actualizado en el documento." << std::endl;
}

// Función para obtener el valor de un campo en un documento
void MotorDatosNoSQL::getField(const std::string& id_document, const std::string& field_key) const {
    // Busca el documento en la tabla
    auto doc_it = tablaDocumentos.find(id_document);

    // Si encuentra el documento, busca el campo dentro de él
    if (doc_it != tablaDocumentos.end()) {
        auto field_it = doc_it->second.find(field_key);
        if (field_it != doc_it->second.end()) { // Si el campo existe, imprime su valor
            std::cout << "Valor: " << field_it->second << std::endl;
            return;
        }
    }

    // Si no encuentra el documento o el campo, muestra un error
    std::cout << "Error: Documento o campo no encontrado." << std::endl;
}

// Función para eliminar un campo de un documento
void MotorDatosNoSQL::deleteField(const std::string& id_document, const std::string& field_key) {
    // Busca el documento en la tabla
    auto doc_it = tablaDocumentos.find(id_document);

    if (doc_it != tablaDocumentos.end()) {
        // Intenta eliminar el campo del documento
        if (doc_it->second.erase(field_key)) { // Retorna `true` si el campo existía
            std::cout << "Eliminando campo del documento..." << std::endl;
        } else {
            std::cout << "Error: El campo no existe en el documento." << std::endl;
        }
    } else {
        std::cout << "Error: Documento no encontrado." << std::endl;
    }
}

// Función para listar todos los campos de un documento
void MotorDatosNoSQL::listDocument(const std::string& id_document) const {
    // Busca el documento en la tabla
    auto doc_it = tablaDocumentos.find(id_document);

    if (doc_it != tablaDocumentos.end()) {
        // Si encuentra el documento, imprime los campos en formato JSON
        std::cout << "{\n  \"" << id_document << "\": {\n";
        for (auto it = doc_it->second.begin(); it != doc_it->second.end(); ++it) {
            // Verifica si es el último elemento para no añadir una coma
            std::cout << "    \"" << it->first << "\": \"" << it->second << "\"";
            if (std::next(it) != doc_it->second.end()) {
                std::cout << ","; // Agrega una coma si no es el último
            }
            std::cout << "\n";
        }
        std::cout << "  }\n}\n";
    } else {
        std::cout << "Error: Documento no encontrado." << std::endl;
    }
}


// Función para listar todos los documentos y sus campos
void MotorDatosNoSQL::listAll() const {
    // Si no hay documentos, muestra un mensaje
    if (tablaDocumentos.empty()) {
        std::cout << "No hay documentos." << std::endl;
        return;
    }

    // Inicia formato JSON como en las bases de datos NoSQL
    std::cout << "{\n";
    for (auto doc_it = tablaDocumentos.begin(); doc_it != tablaDocumentos.end(); ++doc_it) {
        std::cout << "  \"" << doc_it->first << "\": {\n"; // Documento como clave
        for (auto field_it = doc_it->second.begin(); field_it != doc_it->second.end(); ++field_it) {
            // Imprime cada campo como clave-valor
            std::cout << "    \"" << field_it->first << "\": \"" << field_it->second << "\"";
            if (std::next(field_it) != doc_it->second.end()) {
                std::cout << ","; // Agrega una coma si no es el último campo
            }
            std::cout << "\n";
        }
        std::cout << "  }";
        if (std::next(doc_it) != tablaDocumentos.end()) {
            std::cout << ","; // Agrega una coma si no es el último documento
        }
        std::cout << "\n";
    }
    std::cout << "}\n";
}
