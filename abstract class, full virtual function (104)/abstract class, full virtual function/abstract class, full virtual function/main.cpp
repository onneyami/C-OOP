#include <iostream>
#include <string>

using namespace std;

//Абстрактный класс с++ пример. Чисто виртуальная функция

class Weapon{
public:
    virtual void Shoot() = 0;   //для того, чтобы сообщить компилятору, что функция чистая виртуальная нужно после круглых скобок не открывать фигурные, а поставить = 0;
    //после этого этот класс автоматически становится абстрактным и создание объекта такого класса невозможно
};

class Gun : public Weapon{
public:
    void Shoot() override{
        cout << "Boom!" << endl;
    }
    
};

class SubmachineGun : public Gun{
public:
    void Shoot() override{
        cout << "Bo-bo-bo-boom!" << endl;
    }
};

class Bazooka : public Weapon{
public:
    void Shoot() override{
        cout << "Ka-Boooooooom!" << endl;
    }
};

class Knife : public Weapon{
public:
    void Shoot() override{
        cout << "Vjuh!" << endl;
    }
};

class Player{
public:
    void Shoot(Weapon *weapon){
        weapon -> Shoot();
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Player player;
    Bazooka bazooka;
    Knife knife;
    
    player.Shoot(&bazooka);
    player.Shoot(&knife);
    
    return 0;
}

//Чистая виртуальная функция это та, в которой не описана реализация, то-есть она пустая
//Класс, в котором хранится чистая виртуальная функция, называется абстрактный класс
//Создание экземпляров абстрактного класса запрещено

//Если говорить простыми словами, то абстрактный класс по сути это общий самый старший предок всех остальных классов, например для классов Gun, Bazooka, SubMachinegun, Knife общий предок-класс будет Weapon
//Всё это делается для красивого структурированного кода

//Абстрактный класс также может в себе содержать и обычную, не пустую функцию, cледовательно все наследники унаследуют эту функцию
