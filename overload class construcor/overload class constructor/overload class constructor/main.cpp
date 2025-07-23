#include <iostream>
#include <string>

using namespace std;

//Перегрузка конструкторов класса. Что такое перегрузка. Как перегрузить конструктор.

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
    
    Point(){      //по умолчанию теперь в координатах будет 0, 0
        x = 0;
        y = 0;
    }
    
    Point (float valueX, float valueY){
        x = valueX;
        y = valueY;
    }
    
    //теперь в классе есть два конструктора, по умолчанию и пользовательский (наш), соответственно по аналогии с перегрузкой функций теперь и наш конструктор тоже перегружен. При создании объекта автоматически срабатывает конструктор по умолчанию, но, если мы ставим начальные значения, то срабатывает второй конструктор описанный нами
    
    //создавать конструкторы можно в неограниченном количестве
    
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

int main() {
    setlocale(LC_ALL, "RU");
    
    Point a;
    a.Print();
    Point b(3,4);
    b.Print();
    
    return 0;
}


