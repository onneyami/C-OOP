#include <iostream>
#include <string>

using namespace std;

//Порядок вызова конструкторов при множественном наследовании.

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

// Конструкторы при множественном наследовании вызываются поочередно от главного класса-родителя, а затем тот класс-родитель, который идет после запятой и в конце конструктор самого класса


