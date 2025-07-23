#include <iostream>
#include <string>

using namespace std;

//Что такое интерфейс в ООП. Интерфейс c++ пример

class IBicycle {
public:
    void virtual TwistTheWheel () = 0;
    void virtual Ride () = 0;
};

class SimpleBicycle : public IBicycle{
public:
    void TwistTheWheel() override{
        cout << "Вызвался метод TwistTheWheel у SimpleBicycle" << endl;
    }
    
    void Ride() override{
        cout << "Вызвался метод Ride у SimpleBicycle" << endl;
    }
    
};

class Human{
public:
    void RideOn(IBicycle & bicycle){
        cout << "Крутим руль" << endl;
        bicycle.TwistTheWheel();
        cout << "Поехали" << endl;
        bicycle.Ride();
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Human h;
    SimpleBicycle sb;
    
    
    
    h.RideOn(sb);
    
    
    return 0;
}

//по сути интерфейс - это абстрактный класс, в котором все методы чисто виртуальные
