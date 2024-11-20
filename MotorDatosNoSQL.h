#ifndef MOTOR_DATOS_NOSQL_H
#define MOTOR_DATOS_NOSQL_H

#include <iostream>
#include <unordered_map>
#include <string>

class MotorDatosNoSQL {
private:
    // Mapa para almacenar documentos, cada uno con sus campos clave-valor
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> tablaDocumentos;

public:
    // Inserta un campo con clave y valor en un documento existente o crea uno nuevo
    void insertField(const std::string& id_document, const std::string& field_key, const std::string& field_value);

    // Actualiza el valor de un campo en un documento existente
    void updateField(const std::string& id_document, const std::string& field_key, const std::string& new_value);

    // Obtiene el valor de un campo en un documento específico
    void getField(const std::string& id_document, const std::string& field_key) const;

    // Elimina un campo de un documento específico
    void deleteField(const std::string& id_document, const std::string& field_key);

    // Lista todos los campos y valores de un documento específico
    void listDocument(const std::string& id_document) const;

    // Lista todos los documentos y sus campos almacenados en el motor
    void listAll() const;
};

#endif // MOTOR_DATOS_NOSQL_H
