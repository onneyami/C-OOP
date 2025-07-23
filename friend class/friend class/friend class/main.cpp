#include <iostream>
#include <string>

using namespace std;

//Дружественные классы. ООП. friend class. friend c++ что это

//Дружественные классы применяются тогда, когда мы хотим, чтобы все методы одного класса имели доступ к private полям другого класса и чтобы не прописывать дружественные методы для каждого, мы делаем дружественные классы

class Apple;

class Human{
public:
    void TakeApple(Apple &apple);
    
    void EatApple(Apple &apple);
};

class Apple{
    
    friend Human;   //ключевая строка, дающая доступ ко всем private полям Apple классу Human
    
public:
    Apple(int wheight, string color){
        this -> wheight = wheight;
        this -> color = color;
    }
private:
    int wheight;
    string color;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Apple apple(150, "Red");
    
    Human Andrey;
    
    Andrey.TakeApple(apple);
    
    return 0;
}

void Human::TakeApple(Apple &apple){
    cout << "Взято яблоко весом " << apple.wheight << "g" << " и цветом " << apple.color << endl;
}

void Human::EatApple(Apple &apple){
    cout << "Съедено яблоко весом " << apple.wheight << "g" << " и цветом " << apple.color << endl;
}

//Дружественные классы нарушают инкапсуляцию, так как внутри методов есть полный доступ к private полям

//Доп. информация: в методы TakeApple и EatApple мы передаем объект класса Apple, но используем ссылку (&), это делается для того, чтобы передавать адрес памяти объекта класса, а не копировать его элементы в еще один адрес памяти
