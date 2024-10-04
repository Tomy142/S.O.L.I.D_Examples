#include <iostream>
#include <vector>
#include <memory> // Para usar punteros inteligentes

using namespace std;


class Shape {
public:
    virtual void Draw() const = 0; // Método virtual puro para dibujar
};

// Clase para el cuadrado
class Square : public Shape {
public:
    void Draw() const override {
        cout << "Drawing a Square" << endl;
    }
};

// Clase para el círculo
class Circle : public Shape {
public:
    void Draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

// Función para dibujar todas las formas
void DrawAllShapes(const vector<shared_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->Draw(); // Llamada polimórfica al método Draw
    }
}

int main() {
    // Crear formas y agregarlas a la lista
    vector<shared_ptr<Shape>> shapes;
    shapes.push_back(make_shared<Square>());
    shapes.push_back(make_shared<Circle>());
    
    // Dibujar todas las formas
    DrawAllShapes(shapes);

    return 0;
}
