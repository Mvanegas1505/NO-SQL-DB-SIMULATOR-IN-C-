# Nombre del compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++17 -Wall

# Archivos fuente
SRCS = main.cpp AnalizadorNoSQL.cpp MotorDatosNoSQL.cpp 

# Archivos de encabezado
HEADERS = AnalizadorNoSQL.h MotorDatosNoSQL.h 

# Nombre del ejecutable
TARGET = NoSQL_DB

# Regla principal: compila el proyecto
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Regla para limpiar archivos de compilación
clean:
	rm -f $(TARGET) *.o
