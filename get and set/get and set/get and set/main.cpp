#include <iostream>
#include <string>

using namespace std;

//Геттеры, сеттеры
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
        return x;      //если хотим получить информацию из private, пишем Get, просто потому что так принято
    }
    
    float GetY (){
        return y;
    }
    
    void SetX (float valueX){//если хотим внести информацию в private, пишем Set, тоже потому что так принято
        x = valueX;
    }
    
    void Print(){
        cout<< "X is "<< x << endl;
        cout<< "Y is "<< y << endl;
    }
    
    };



int main() {
    setlocale(LC_ALL, "RU");
    
    Point a;
    
    a.SetX(4.5);
    a.Print();
    a.GetY();
    
    return 0;
}

//в объектно - ориентированном программировании не принято давать прямой доступ к полям класса, на нашем примере к x и y, соответственно применяется инкапсуляция, пример инкапсуляции выше
