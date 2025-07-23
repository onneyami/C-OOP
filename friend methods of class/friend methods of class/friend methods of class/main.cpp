#include <iostream>
#include <string>

using namespace std;

//Дружественный метод класса. ООП. friend c++ что это. Функции друзья

class Apple;

class Human{
public:
    void TakeApple(Apple &apple);
};

class Apple{
public:
    Apple(int wheight, string color){
        this -> wheight = wheight;
        this -> color = color;
    }
private:
    int wheight;
    string color;
    
    friend void Human::TakeApple(Apple &apple);     //ключевая строчка, дающая доступ методу Human к private полям класса Apple
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Apple apple(150, "Red");
    
    Human Andrey;
    
    Andrey.TakeApple(apple);
    
    return 0;
}

void Human::TakeApple(Apple &apple){    //вынесли метод вне класса для того, чтобы он видел поля у Apple
    cout << "Взято яблоко весом " << apple.wheight << " и цветом " << apple.color << endl;
}
//можно выносить под main
