#include <iostream>
#include <string>

using namespace std;

//методы класса
//функции класса

class Human{
public:
    string name;
    int age;
    int weight;
    
    void GetInfo(){        //метод для класса нужно обязательно прописывать внутри класса, иначе это будет внешней функцией
        cout<< "The name is "<< name << endl;
        cout<< "The age is "<< age << endl;
        cout<< "The weight is "<< weight << endl;
    }
};

class Point{
public:
    float x;
    float y;
    float z;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Human FirstHuman;
    FirstHuman.age = 17;
    FirstHuman.name = "Andrey";
    FirstHuman.weight = 75;
    
    FirstHuman.GetInfo();
    
    
    
    return 0;
}

//методы класса и функции класса - это по сути одно и то же
