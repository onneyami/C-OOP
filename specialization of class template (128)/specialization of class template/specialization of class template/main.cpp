#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//Специализация шаблона класса

template <typename T>
class Printer{
public:
    void Print(T value){
        cout << value << endl;
    }
};

template<>      //когда создаем специализированный шаблон, прописываем template<> сверху, а перед фигурными скобками внутри угловых пишем тип данных, для которых будет применяться этот шаблон
class Printer<string>{
public:
    void Print(string value){
        cout << "_" << value << "_" << endl;
    }
};

//таким образом именно для данных с типом string, то будет работать класс описанный ниже верхнего

int main() {
    setlocale(LC_ALL, "RU");
    
    Printer<string> p;
    p.Print("Hello World!");
    
    return 0;
}
