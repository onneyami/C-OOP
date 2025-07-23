#include <iostream>
#include <string>

using namespace std;

//Вызов конструктора базового класса из конструктора класса-наследника

class A{
public:
    A(){
        msg = "Пустое сообщение";
    }
    
    A(string msg){
        this -> msg = msg;
    }
    
    ~A(){}
    
    void PrintMsg(){
        cout << msg << endl;
    }
    
private:
    string msg;
};

class B : public A{
public:
    B():A("Наше новое сообщение")      //если этого не указать, то компилятор будет всегда пытаться вызвать конструктор по умолчанию
    {
        
    }
    
    ~B(){}
};

int main() {
    setlocale(LC_ALL, "RU");
    
    B b;
    b.PrintMsg();
    
    return 0;
}

