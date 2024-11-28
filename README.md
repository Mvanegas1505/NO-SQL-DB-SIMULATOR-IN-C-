
# Final Project: NoSQL Data Engine  

## Project Overview  
This project implements a basic NoSQL data engine in C++. The goal is to create a system that allows users to manage documents using a hash-based structure (e.g., `unordered_map` in C++) to store records with multiple key-value fields, uniquely identified by an `id_document`.  

The project demonstrates the application of data structures, data manipulation, and system design skills, as well as a practical understanding of CRUD operations within a NoSQL context.  

## Document Structure  
Each document follows this structure:  

```json
{
  "id_document": "ABC123",
  "name": "Edison",
  "age": "52",
  "program": "Systems Engineering"
}
```

## CRUD Operations  
The NoSQL engine supports the following operations through commands:  

- **INSERT_FIELD:** Adds a field to a document or creates the document if it doesn't exist.  
- **UPDATE_FIELD:** Updates the value of a field in an existing document.  
- **GET_FIELD:** Retrieves the value of a specific field in a document.  
- **DELETE_FIELD:** Removes a specific field from a document.  
- **LIST_DOCUMENT:** Lists all fields and values in a specific document.  
- **LIST_ALL:** Lists all documents in the database, along with their respective fields and values.  

## Command Syntax (BNF Description)  
Below is the BNF syntax definition for the CRUD commands:  

```
<command> ::= <insert_field> 
            | <update_field> 
            | <get_field> 
            | <delete_field> 
            | <list_document> 
            | <list_all>

<insert_field> ::= "INSERT_FIELD" <id_document> <field_key> <field_value>
<update_field> ::= "UPDATE_FIELD" <id_document> <field_key> <new_value>
<get_field> ::= "GET_FIELD" <id_document> <field_key>
<delete_field> ::= "DELETE_FIELD" <id_document> <field_key>
<list_document> ::= "LIST_DOCUMENT" <id_document>
<list_all> ::= "LIST_ALL"

<id_document> ::= <string>
<field_key> ::= <string>
<field_value> ::= <string>
<new_value> ::= <string>
```

## Code Highlights  
### Main Class: `MotorDatosNoSQL`  
The core class, `MotorDatosNoSQL`, implements the NoSQL engine's functionality:  

- **`insertField`**: Adds a new field to a document.  
- **`updateField`**: Updates the value of an existing field.  
- **`getField`**: Retrieves a field's value from a document.  
- **`deleteField`**: Deletes a specific field from a document.  
- **`listDocument`**: Lists all fields and values in a document.  
- **`listAll`**: Displays all documents and their content.  

### Example Usage in Main Function  

```cpp
int main() {
    MotorDatosNoSQL db;

    AnalizadorNoSQL parser(db);

    std::string comando;

    
    while (true) {
        std::cout << "NoSQL> ";               
        std::getline(std::cin, comando);     
        if (comando == "exit" || comando == "EXIT") break;      
        parser.analizar(comando);            
    }

    return 0; 
}
```

### Sample Output  
```plaintext
{
  "ABC1505": {
    "Name": "Martin",
    "Age": "19",
    "degree": "Computer Science"
  }
}
```

## Installation and Usage  
1. Clone the repository:  
   ```bash
   git clone https://github.com/Mvanegas1505/NO-SQL-DB-SIMULATOR-IN-C-
   cd NO-SQL-DB-SIMULATOR-IN-C-
   ```
2. Compile the code:  
   ```bash
   g++ -o NoSQLSimulator main.cpp MotorDatosNoSQL.cpp
   ```
   Or using make file:
    ```bash
    make clean
    make
      ```
4. Run the executable:  
   ```bash
   ./NoSQLSimulator
   ```

## Contributions  
Feel free to fork the repository and submit pull requests for improvements or additional features!  
  
