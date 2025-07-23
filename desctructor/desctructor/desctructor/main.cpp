#include <iostream>
#include <string>

using namespace std;

//Деструктор что это. Зачем нужен деструктор класса в ООП. Деструктор с параметрами. Перегрузка.

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
    }
    
    Point (float valueX, float valueY){
        x = valueX;
        y = valueY;
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
    
    ~MyClass(){     //деструктор вызывается автоматически при выходе из области применения объекта класса, деструктор в отличии от конструкторов, может быть только один
        cout << "Объект " << data << " Вызвался деструктор" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    MyClass(5);
    
    return 0;
}

//деструктор никогда не сможет принимать параметры, так как это делает конструктор

//если мы в конструкторе выделяем динамическую память под, к примеру, массив, то в деструкторе мы должны позаботиться об очистке, то-есть в конструкторе new int, а в деструкторе delete[]
