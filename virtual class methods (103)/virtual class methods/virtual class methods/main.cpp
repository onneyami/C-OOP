#include <iostream>
#include <string>

using namespace std;

//Виртуальные методы класса c++. Ключевое слово virtual, override

class Gun{
public:
    virtual void Shoot(){       //для того, чтобы у класса-наследника, в нашем случае: класса пистолет-пулемет реализовать метод Shoot по-другому следует указывать ключевое слово virtual
        cout << "Boom!" << endl;
    }
};

class SubmachineGun : public Gun{
public:
    void Shoot() override{     //чтобы переопределить метод Shoot для класса-наследника следует следить за тем, чтобы сигнатура этого метода была указана точно такая же, как и в классе-родителе, то-есть такой же тип данных, такое же название и ОБЯЗАТЕЛЬНО он не должен принимать никаких значений, то-есть в () должно быть пусто, либо же вместо самостоятельного контроля этого всего можно прописать ключевое слово override и тогда компилятор будет следить за всем этим за нас автоматически
        cout << "Bo-bo-bo-boom!" << endl;
    }
};

class Bazooka : public Gun{
public:
    void Shoot() override{
        cout << "Ka-Boooooooom!" << endl;
    }
};

class Player{
public:
    void Shoot(Gun *gun){
        gun -> Shoot();
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    SubmachineGun machinegun;
    
    /*Gun *weapon = &gun;
    weapon->Shoot();*/            //выведется одиночный выстрел
    
    /*Gun *weapon = &machinegun;
     weapon->Shoot();*/           //выведется не одиночный выстрел
    
    Player player;
    player.Shoot(&machinegun);      //указатель может работать на любом наследнике класса-родителя
    
    Bazooka bazooka;
    
    player.Shoot(&bazooka);
    
    return 0;
}

//Главный вопрос: зачем вообще нужен указатель и вся эта морока с полиморфизмом?
//Ответ: в нашем случае для каждого вида оружия в классе Player пришлось бы перегружать функцию Shoot, что заняло бы гораздо больше времени и места кода
