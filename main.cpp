#include <iostream>
#include <unordered_map>
#include <string>
#include "MotorDatosNoSQL.h" 


int main() {
    MotorDatosNoSQL db;
    db.insertField("ABC123", "nombre", "Edison");
    db.insertField("ABC123", "edad", "52");
    db.insertField("ABC123", "programa", "Ingenieria de Sistemas");
    db.listDocument("ABC123");

    return 0;
}
