#include <iostream>
#include <string>

using namespace std;

//Ключевое слово this в ООП. Что означает. Что это такое. Для чего нужен this указатель C++

class Human{
public:
    string name;
    int age;
    int weight;
    
    void GetInfo(){
        cout<< "The name is "<< name << endl;
        cout<< "The age is "<< age << endl;
        cout<< "The weight is "<< weight << endl;
    }
};

class Point{
private:
    float x;
    float y = 3.67f;

public:
    
    Point(){
        x = 0;
        y = 0;
        cout<< this << " Constructor" << endl;
    }
    
    Point (float valueX, float valueY){
        x = valueX;
        y = valueY;
        cout<< this << " Constructor" << endl;
    }
    
    
    float GetX (){
        return x;
    }
    
    float GetY (){
        return y;
    }
    
    void SetX (float valueX){
        x = valueX;
    }
    
    void SetY (float valueY){
        y = valueY;
    }
    
    void Print(){
        cout<< "X is "<< x << endl;
        cout<< "Y is "<< y << endl;
    }
    
    };

class CoffeGrinder{
private:
    
    bool CheckVoltage(){
        return true;
    }
    
public:
    void Start(){
        if(CheckVoltage() == true){
            cout << "CoffeGrinder is ON" << endl;
        }
        else {
            cout << "CoffeGrinder is OFF, check the voltage." << endl;
        }
    }
};

class MyClass{
private:
    int data;
public:
    MyClass(int value){
        data = value;
        cout << "Объект " << data << " Вызвался конструктор"<< endl;
    }
    
    ~MyClass(){
        cout << "Объект " << data << " Вызвался деструктор" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Point a;
    Point b(5,6);
    
    return 0;
}

//указатель this можно использовать только внутри класса

