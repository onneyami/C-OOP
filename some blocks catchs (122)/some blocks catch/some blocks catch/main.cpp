#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Несколько блоков catch. Обработка исключений С++

void Foo(int value){
    
    if(value < 0){
        //throw exception();
        throw "Число меньше 0!";
    }
    if(value == 0){
        throw exception();
    }
    
    cout << "Переменная = " << value << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    try{
        Foo(-13);
    }
    catch(const exception &ex){
        cout << "Блок 1 Мы поймали " << ex.what() << endl;
    }
    catch(const char *ex){      //ловим наше throw "Число меньше 0"
        cout << "Блок 2 Мы поймали " << ex << endl;
    }
    catch(...){
        cout << "Что-то пошло не так" << endl;   //когда мы ловим три точки это значит, что мы ловим то, что бросил throw, но оно не подошло не под один из catchей, но прописывать его нужно ОБЯЗАТЕЛЬНО после всех остальных кэтчей
    }
    
    return 0;
}


