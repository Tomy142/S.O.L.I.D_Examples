#include <iostream>
using namespace std;

// Clase para la lógica geométrica del rectángulo
class GeometricRectangle {
private:
    int width;
    int height;

public:
    GeometricRectangle(int w, int h) : width(w), height(h) {}

    int area() const {
        return width * height;
    }

    int perimeter() const {
        return 2 * (width + height);
    }
};

// Clase para la representación gráfica del rectángulo
class RectangleDrawer {
public:
    static void draw(const GeometricRectangle& geoRect) {
        cout << "Drawing rectangle:" << endl;
        for (int i = 0; i < geoRect.perimeter() / 2; ++i) {
            for (int j = 0; j < geoRect.perimeter() / 2; ++j) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

// Clase para la aplicación gráfica
class ApplicationGraphical {
private:
    GeometricRectangle rect;

public:
    ApplicationGraphical(GeometricRectangle r) : rect(r) {}
    ~ApplicationGraphical() {}

    void mostrar() {
        RectangleDrawer::draw(rect);
    }
};

int main() {
    // Crear un rectángulo
    cout << "---------------- " << endl;
    GeometricRectangle rect(4, 2);

    // Mostrar el área
    cout << "Area: " << rect.area() << endl;

    cout << "---------------- " << endl;
    ApplicationGraphical app(rect);
    app.mostrar();

    return 0;
}
