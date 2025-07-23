#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Генерация исключений с++ пример. throw c++ пример

//throw - бросить с английского, поэтому исключения именно "бросаются"

void Foo(int value){
    
    if(value < 0){
        throw exception("Число меньше 0 !!!");    //генерация исключения: мы не хотим, чтобы функция работала с числами меньше 0
    }
    
    cout << "Переменная = " << value << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    try{
        Foo(-13);
    }
    catch(const exception &ex){
        
        ex.what();
        
    }
    
    return 0;
}

