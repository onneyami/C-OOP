#include <iostream>
#include <string>

using namespace std;

//Инкапсуляция

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
    
    float GetX (){
        return x;
    }
    
    float GetY (){
        return y;
    }
    
    void SetX (float valueX){
        x = valueX;
    }
    
    void Print(){
        cout<< "X is "<< x << endl;
        cout<< "Y is "<< y << endl;
    }
    
    };

class CoffeGrinder{
private:
    
    bool CheckVoltage(){       //скрытый обязательный функционал, пользователю не нужно ничего нажимать
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
    
    CoffeGrinder a;
    a.Start();
    
    return 0;
}

//в объектно - ориентированном программировании не принято давать прямой доступ к полям класса, на нашем примере к x и y, соответственно применяется инкапсуляция, пример инкапсуляции выше

