#include <iostream>
#include <string>

using namespace std;

//Статические методы класса зачем нужны. Модификатор static. Как влияет. ООП.

class Apple{
    public:
    Apple(int wheight, string color){
        this -> wheight = wheight;
        this -> color = color;
        Count++;
        ID = Count;
    }
    
    int GetID(){
        return ID;
    }
    
    static int GetCount(){      //чтобы работать со статической переменной, если хотим сделать это через геттер, как здесь, то он ОБЯЗАТЕЛЬНО должен быть тоже статическим
        return Count;
    }
    
private:
    int wheight;
    string color;
    int ID;
    static int Count;     //защищаем количество при помощи private
};

int Apple::Count = 0;

int main() {
    setlocale(LC_ALL, "RU");
    
    Apple apple0(150, "Red");
    Apple apple1(200, "Green");
    Apple apple2(100, "Yellow");
    
    cout << apple0.GetID() << endl;
    cout << apple1.GetID() << endl;
    cout << apple2.GetID() << endl;
    
    cout << "Число яблок: " << Apple::GetCount() << endl;
    
    return 0;
}

//в нашем случае метод GetCount можно вызывать и без объектов класса, то-есть даже тогда, когда созданных яблок нет

//также статический метод может работать только со статическими переменными!!!!!



