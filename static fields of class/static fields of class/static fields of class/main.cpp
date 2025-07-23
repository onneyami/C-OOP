#include <iostream>
#include <string>

using namespace std;

//static что это. Статические поля класса. Инициализация. Ключевое слово static

//static переменная означает, что она для всех классов одна, то-есть если мы создали ее в классе_1 и затем изменяем в классе_2, то изначальное значение для класса_2 будет то, что было после изменений в классе_1 и так далее

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
        Count++;      //каждый раз при создании нового "яблока" количество увеличивается на 1
    }
private:
    int wheight;
    string color;
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


