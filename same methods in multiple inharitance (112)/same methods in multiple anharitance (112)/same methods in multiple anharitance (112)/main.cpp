#include <iostream>
#include <string>

using namespace std;

//С++ множественное наследование одинаковые методы.

class Car{
public:
    void Use(){
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
    void Use (){
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
    ((Car)fc).Use();     //для того, чтобы использовать метод из опеределенного класса-родителя, нужно использовать такой синтаксис ((Класс-родитель)название объекта).метод;
    
    return 0;
}





