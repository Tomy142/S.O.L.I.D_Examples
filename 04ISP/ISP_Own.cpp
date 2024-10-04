#include <iostream>
#include <string>

using namespace std;

//Interfaces
class Serviceable
{
    virtual void Service() = 0;
};

class Refuelable
{
    virtual void Refuel() = 0;
};

class ElectricRechargeable
{
    virtual void ElectricRecharge() = 0;
};

//Implementacion

class Car : public Serviceable, Refuelable
{
    public:
        void Service()override
        {
            cout<<" Realizando Mantenimiento al auto"<<endl;
        }
        void Refuel()override
        {
            cout<<"Cargando el tanque del auto"<<endl;
        }
};

class ElectricCar : public Serviceable, ElectricRechargeable
{
    public:
        void Service()override
        {
            cout<<"Realizando mantenimiento al auto electrico"<<endl;
        }
        void ElectricRecharge()override
        {
            cout<<"Cargando la bateria del auto"<<endl;
        }
};

class Bycicle :public Serviceable
{
    public:
        void Service()override
        {
            cout<<"Realizando mantenimiento a la bicicleta"<<endl;
        }
};

int main()
{
    Car car;
    ElectricCar electricCar;
    Bycicle bycicle;

    //Auto
    cout<<"Auto:"<<endl;
    car.Refuel();
    car.Service();
    cout<<endl;

    //Auto electrico
    cout<<"Auto Electrico:"<<endl;
    electricCar.Service();
    electricCar.ElectricRecharge();
    cout<<endl;

    //bicicleta
    cout<<"Bicicleta:"<<endl;
    bycicle.Service();


    return 0;
}