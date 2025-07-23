#include <iostream>
#include <string>

using namespace std;

//id generator. Генератор уникальных идентификаторов с использованием static переменной

//id применяется к примеру тогда, когда по характеристикам два объекта полностью идентичные, а различать их как-то надо

class Apple;

class Human{
public:
    void TakeApple(Apple &apple);
    
    void EatApple(Apple &apple);
};

class Apple{
    
    friend Human;
    
public:
    
    static int Count;
    
    Apple(int wheight, string color){
        this -> wheight = wheight;
        this -> color = color;
        Count++;
        ID = Count;      //для каждого нового яблока ID будет новый, в нашем случае по порядку по возрастанию
    }
    
    int GetID(){      //получаем при помощи метода значение ID
        return ID;
    }
    
private:
    int wheight;
    string color;
    int ID;
};

int Apple::Count = 0;

int main() {
    setlocale(LC_ALL, "RU");
    
    Apple apple(150, "Red");
    
    cout << "Число яблок: " << Apple::Count << endl;
    
    return 0;
}

void Human::TakeApple(Apple &apple){
    cout << "Взято яблоко весом " << apple.wheight << "g" << " и цветом " << apple.color << endl;
}

void Human::EatApple(Apple &apple){
    cout << "Съедено яблоко весом " << apple.wheight << "g" << " и цветом " << apple.color << endl;
}



