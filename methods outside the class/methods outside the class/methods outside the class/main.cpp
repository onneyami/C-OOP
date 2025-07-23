#include <iostream>
#include <string>
 
using namespace std;

// Определение методов вне класса. Вынести функцию в из класса. Вынести описание метода вне класса.

class MyClass{
public:
    MyClass();
    ~MyClass();
    
    void PrintMessage();    //оставляем прототип метода
        
private:
    
};

MyClass::MyClass(){
    
}

MyClass::~MyClass(){
    
}

void MyClass::PrintMessage(){
    cout << "Hello!" << endl;
}


int main(){
    setlocale(LC_ALL, "RU");
    
    MyClass a;
    a.PrintMessage();
    
    return 0;
}

// для чего это вообще нужно?
// если класс большой, чтобы не потеряться глазами, записывают просто прототипы методов, а сами методы вынесены вне этого класса 
