#include <iostream>
#include <string>

using namespace std;

//Множественное наследование c++ пример

class Car{
public:
    void Drive(){
        cout << "Я еду" << endl;
    }
};

class Airplane{
public:
    void Fly (){
        cout << "Я лечу" << endl;
    }
};

class FlyingCar : public Car, public Airplane{    //чтобы унаследоваться от нескольких классов нужно перечислить модификаторы доступа и названия классов через запятую
public:
    FlyingCar(){
        cout << "Вызвался конструктор" << endl;
    }
    
    ~FlyingCar(){
        cout << "Вызвался деструктор" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    FlyingCar fc;
    fc.Drive();
    fc.Fly();
    
    Car *ptrC = &fc;
    Airplane *ptrA = &fc;    //так как мы наследуемся от двух классов, то теперь ссылку на объект класса может содержать элемент типа класса Car, Airplane
    
    return 0;
}

//Можно унаследовать один класс от нескольких, в таком случае класс получит все характеристики всех классов, от которых наследуется


