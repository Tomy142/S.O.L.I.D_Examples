#include <iostream>
#include <vector>
#include <memory>

// Clase abstracta IterableContainer que permite la iteración
class IterableContainer {
public:
    virtual ~IterableContainer() {}
    virtual void iterate() const = 0;
};

// Clase abstracta MemberContainer que permite verificar la membresía
class MemberContainer {
public:
    virtual ~MemberContainer() {}
    virtual bool contains(int element) const = 0;
};

// Clase Set para un conjunto genérico de enteros
class Set : public IterableContainer, public MemberContainer {
private:
    std::vector<int> elements;

public:
    void add(int element) {
        elements.push_back(element);
    }

    void iterate() const override {
        for (const auto& elem : elements) {
            std::cout << "Set Element: " << elem << std::endl;
        }
    }

    bool contains(int element) const override {
        for (const auto& elem : elements) {
            if (elem == element) return true;
        }
        return false;
    }
};

// Clase abstracta PersistentObject que representa objetos persistentes
class PersistentObject {
public:
    virtual ~PersistentObject() {}
    virtual void save() const = 0;  // Método para simular la persistencia del objeto
};

// Clase PersistentSet para un conjunto de objetos persistentes
class PersistentSet : public IterableContainer, public MemberContainer {
private:
    std::vector<std::shared_ptr<PersistentObject>> elements;

public:
    void add(const std::shared_ptr<PersistentObject>& obj) {
        elements.push_back(obj);
    }

    void iterate() const override {
        for (const auto& elem : elements) {
            elem->save();
        }
    }

    bool contains(int element) const override {
        // Implementar lógica de comparación si es necesario
        return false; // Esto depende de la implementación de PersistentObject
    }
};

// Clase proporcionada por un tercero para manejar objetos persistentes
class ThirdPartyPersistentSet {
public:
    void add(PersistentObject& obj) {
        obj.save();
        std::cout << "Added object to third-party persistent set." << std::endl;
    }
};

// Clase PersistentNumber que deriva de PersistentObject
class PersistentNumber : public PersistentObject {
private:
    int value;

public:
    PersistentNumber(int v) : value(v) {}

    void save() const override {
        std::cout << "Saving Persistent Number: " << value << std::endl;
    }

    int getValue() const {
        return value;
    }
};

// Implementación del main
int main() {
    // Uso de Set normal
    Set mySet;
    mySet.add(10);
    mySet.add(20);
    mySet.iterate();

    // Uso de PersistentSet con objetos persistentes
    PersistentSet myPersistentSet;
    std::shared_ptr<PersistentObject> p1 = std::make_shared<PersistentNumber>(100);
    std::shared_ptr<PersistentObject> p2 = std::make_shared<PersistentNumber>(200);

    myPersistentSet.add(p1);
    myPersistentSet.add(p2);
    myPersistentSet.iterate();

    // Uso de ThirdPartyPersistentSet
    ThirdPartyPersistentSet thirdPartySet;
    thirdPartySet.add(*p1);  // Paso del objeto persistente

    return 0;
}

