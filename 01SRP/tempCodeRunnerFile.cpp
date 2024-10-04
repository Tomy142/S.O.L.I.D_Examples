// Clase para la representación gráfica del rectángulo
class Rectangle {
private:
    GeometricRectangle geoRect;

public:
    Rectangle(int w, int h) : geoRect(w, h) {}

    void draw() const {
        std::cout << "Drawing rectangle:" << std::endl;
        for (int i = 0; i < geoRect.perimeter() / 2; ++i) {
            for (int j = 0; j < geoRect.perimeter() / 2; ++j) {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
    }

    int area() const {
        return geoRect.area();
    }
};