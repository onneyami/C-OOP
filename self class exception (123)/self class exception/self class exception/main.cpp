#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Свой класс exception c++. Создание собственного класса исключений.

/*class MyException : public exception{    //наследуем наш класс MyException от базового класса exception, чтобы мы могли его потом бросить в try catch
public:
    MyException(char *msg, int dataState) : exception(msg){
        this -> dataState = dataState;
    }
    int GetDataState(){
        return dataState;
    }
private:
    int dataState;
};*/

void Foo(int value){
    
    /*if(value < 0){
        throw exception("Число меньше 0 !!!");
    }*/
    
    /*if(value == 1){
        throw MyException("Число равно 1!!!", value);
    }*/
    
    cout << "Переменная = " << value << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    try{
        Foo(1);
    }
    catch(exception &ex){
        
        cout << "Мы поймали" << ex.what() << endl;
        //cout << "Состояние данных" << ex.GetDataState() << endl;
        
    }
    
    return 0;
}


