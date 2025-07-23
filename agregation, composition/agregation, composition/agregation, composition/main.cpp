#include <iostream>
#include <string>

using namespace std;

//Что такое агрегация и композиция. Отношения между классами и объектами.

class Cap{
public:
    
    string GetColor(){
        return color;
    }
    
private:
    string color = "red";
};

class Human{
public:
    void Think(){
        brain.Think();     //пример дилегирования
    }
    
    void InspectTheCap(){
        cout << "Моя кепка " << cap.GetColor() << endl;
    }
    
private:
    class Brain{
    public:
        void Think(){
            cout << "Я думаю!" << endl;
        }
    };
    Brain brain;
    Cap cap;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Human human;
    human.Think();   //по сути здесь композиция вызывает метод Think у вложенного класса Brain, а не у самого human
    
    human.InspectTheCap(); //а вот здесь агрегация позволяет взаимодействовать классу Human с классом cap, при этом кепка не привязана строго к Human
    
    return 0;
}

// агрегация позволяет использовать вложенный класс еще и в других местах

// композиция не позволяет использовать вложенный класс вне объемлющего класса
