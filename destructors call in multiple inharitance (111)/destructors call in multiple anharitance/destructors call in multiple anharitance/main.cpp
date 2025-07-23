#include <iostream>
#include <string>

using namespace std;

//Порядок вызова деструкторов при множественном наследовании.

class Car{
public:
    void Drive(){
        cout << "Я еду" << endl;
    }
    
    Car(){
        cout << "Вызвался конструктор класса Car" << endl;
    }
    
    ~Car(){
        cout << "Вызвался деструктор класса Car" << endl;
    }
};

class Airplane{
public:
    void Fly (){
        cout << "Я лечу" << endl;
    }
    
    Airplane(){
        cout << "Вызвался конструктор класса Airplane" << endl;
    }
    
    ~Airplane(){
        cout << "Вызвался деструктор класса Airplane" << endl;
    }
};

class FlyingCar : public Car, public Airplane{
public:
    FlyingCar(){
        cout << "Вызвался конструктор класса FlyingCar" << endl;
    }
    
    ~FlyingCar(){
        cout << "Вызвался деструктор класса FlyingCar" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    FlyingCar fc;
    
    return 0;
}

// Деструкторы при множественном наследовании вызываются поочередно от созданного конструктора класса и в обратном порядке затем классы-родители



