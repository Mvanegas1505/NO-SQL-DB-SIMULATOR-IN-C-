#include <iostream>
#include <unordered_map>
#include <string>
#include "MotorDatosNoSQL.h" 
#include "AnalizadorNoSQL.h"


int main() {
    MotorDatosNoSQL db;
                    
    AnalizadorNoSQL parser(db);  

    std::string comando;
    while (true) {
        std::cout << "NoSQL> ";               
        std::getline(std::cin, comando);    
        if (comando == "exit") break;        
        parser.analizar(comando);        
    }

    return 0;

    return 0;
}
