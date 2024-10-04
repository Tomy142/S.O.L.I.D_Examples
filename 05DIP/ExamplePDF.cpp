#include <iostream>
#include <string>

// 1. Clase abstracta Reader (Lector)
class Reader {
public:
    virtual char leer() = 0; 

};

// 2. Clase abstracta Writer (Escritor)
class Writer {
public:
    virtual void escribir(char c) = 0;  // Método abstracto para escribir un carácter

};

// 3. Clase Copy que depende de las abstracciones Reader y Writer
class Copy {
private:
    Reader& reader;  // Dependencia de un Reader
    Writer& writer;  // Dependencia de un Writer

public:
    // Constructor que acepta referencias a un Reader y un Writer
    Copy(Reader& r, Writer& w) : reader(r), writer(w) {}

    // Método para realizar la copia
    void ejecutar() {
        while (true) {
            char c = reader.leer();  // Leer un carácter
            if (c == '\n') break;    // Terminar cuando se lee un salto de línea
            writer.escribir(c);      // Escribir el carácter
        }
    }
};

// 4. Implementación concreta de un Reader (Lectura desde teclado)
class ReaderTeclado : public Reader {
public:
    char leer() override {
        char c;
        std::cin.get(c);  // Leer desde el teclado
        return c;
    }
};

// 5. Implementación concreta de un Writer (Escritura a impresora - simulada)
class WriterImpresora : public Writer {
public:
    void escribir(char c) override {
        std::cout << "Impresora recibe: " << c << std::endl;  // Simular la escritura en una impresora
    }
};

// Función principal para probar el ejemplo
int main() {
    ReaderTeclado reader;   // Crear un lector de teclado
    WriterImpresora writer; // Crear un escritor de impresora

    Copy copy(reader, writer); // Crear la clase Copy con el lector y el escritor
    std::cout << "Ingrese texto (termine con Enter): ";
    copy.ejecutar();  // Ejecutar la copia desde el lector al escritor

    return 0;
}
