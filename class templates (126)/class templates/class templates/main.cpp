#include <iostream>
#include <string>

using namespace std;

//Шаблоны классов с++ примеры. Обобщенные классы

class Point{
public:
    Point(){
        x = y = z = 0;
    }
    
    Point(int x, int y, int z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    
private:
    int x;
    int y;
    int z;
};

template <typename T1, typename T2>    //прописываем как и с шаблонными функциями, внутри <> прописываем через запятую наши типы данных (шаблонных)
class MyClass{
public:
    
    MyClass(T1 value, T2 value2){
        this -> value = value;
        this -> value2 = value2;
    }
    
    void DataTypeSize(){
        cout << sizeof(value) << endl;
        cout << sizeof(value2) << endl;
    }
    
private:
    T1 value;
    T2 value2;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    int a = 5;
    Point p;
    
    MyClass<int, Point> c(a,p);      //при создании объекта класса по шаблонному классу прописываем <тип данных> с которым будем работать
    c.DataTypeSize();
    
    
    
    return 0;
}
