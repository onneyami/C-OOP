#include <iostream>
#include <string>

using namespace std;

//Порядок вызова конструкторов при наследовании

class A{
public:
    A(){
        cout << "Вызвался конструктор класса А" << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "Вызвался конструктор класса B" << endl;
    }
};

class C : public B{
    public:
    C(){
        cout << "Вызвался конструктор класса C" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    C c;
    
    return 0;
}

//Итог: конструкторы вызываются от старшего предка к младшему
