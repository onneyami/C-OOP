#include <iostream>
#include <string>

using namespace std;

//Виртуальное наследование c++. Ромбовидное наследование c++


//В этом случае не будет проблемой, что для каждого подкласса у класса graphiccard вызываются конструкторы у component
class Component{
public:
    Component(string companyName){
        cout << "Конструктор Component" << endl;
        this -> companyName = companyName;
    }
    string companyName;
};

class GPU : public Component{
public:
    GPU(string companyName) :Component(companyName){
        cout << "Конструктор GPU" << endl;
    }
};

class Memory : public Component{
public:
    Memory(string companyName) :Component(companyName){
        cout << "Конструктор Memory" << endl;
    }
};

class GraphicCard : public Memory, public GPU{
public:
    GraphicCard(string MemoryCompanyName,string GPUCompanyName):Memory(MemoryCompanyName),GPU(GPUCompanyName){
        cout << "Конструктор GraphicCard" << endl;
    }
};

//В этом случае появляется такая проблема: для финального класса OrcWarrior вызываются конструкторы Character -> Orc, Character -> Warrior и затем сам OrcWarrior, следовательно количество HP будут храниться в нескольких местах. Это значит, что к примеру если Orc убьют, то HP еще будет у Warrior

//Здесь же и суть ромбовидного наследования - это позволяет вызывать конструктор только для одного Character

//Ключевое слово virtual перед классом от которого наследуемся решает эту проблему
class Character{
public:
    Character(){
        cout << "Конструктор Character" << endl;
    }
    int HP;
};

class Orc : public virtual Character{
public:
    Orc(){
        cout << "Конструктор Orc" << endl;
    }
};

class Warrior : public virtual Character{
public:
    Warrior(){
        cout << "Конструктор Warrior" << endl;
    }
};

class OrcWarrior : public Orc, public Warrior{
public:
    OrcWarrior(){
        cout << "Конструктор OrcWarrior" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    GraphicCard("Samsung", "AMD");
    
    OrcWarrior orc;
    
    Orc orc1;
    
    Warrior war1;
    
    return 0;
}
