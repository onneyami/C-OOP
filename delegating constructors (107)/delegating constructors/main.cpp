#include <iostream>
#include <string>

using namespace std;

//Делегирующие конструкторы c++. Вызов конструктора из конструктора

class Human{
public:
    
    Human(string Name){
        this -> Name = Name;
        int Age = 0;
        int Weight = 0;
    }
    
    Human(string Name, int Age):Human(Name){
        this -> Age = Age;
    }
    
    Human(string Name, int Age, int Weight):Human(Name, Age){
        this -> Weight = Weight;
    }
    
    string Name;
    int Age;
    int Weight;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Human h("Аристарх");
    Human h1("Сергей", 30);
    Human h2("Алексей", 18, 65);
    
    return 0;
}

//делегирующие конструкторы используются лишь для отсутсвия дублирования кода
