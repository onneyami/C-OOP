#include <iostream>
#include <string>

using namespace std;

//Модификаторы доступа при наследовании. private public protected Спецификаторы доступа

class A{
public:
    string msgOne = "1";
private:
    string msgTwo = "2";
protected:
    string msgThree = "3";
};

class B : public A{      //класс В содержит в себе все поля класса А, но доступ к ним зависит от модификаторов доступа, установленных в классе В
public:
    void PrintMsg(){
        cout << msgThree << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    B b;
    //b.msgThree;   будет ошибка
    return 0;
}

//Разница модификаторов доступа:
//public - доступно всем и везде
//private - закрыто ото всех, кроме класса ,в котором оно было создано
//protected - обратиться напрямую нельзя, но доступ к нему внутри классах-наследниках обращаться можно

//Разница модификаторов доступа при наследовании, то-есть то, что пишется после :
// таблица в папке с этим кодом
