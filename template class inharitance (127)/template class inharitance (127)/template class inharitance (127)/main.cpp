#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

//Наследование шаблонных классов

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

template <typename T1>
class TypeSize{
public:
    
    TypeSize(T1 value){
        this -> value = value;
    }
    
    void DataTypeSize(){
        cout << sizeof(value) << endl;
    }
    
protected:
    T1 value;
};

template <typename T1>
class TypeInfo : public TypeSize<T1>{
public:
    TypeInfo(T1 value):TypeSize<T1>(value){
        
    }
    
    void ShowTypeName(){
        cout << "Название типа: " << typeid(value).name() << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    int a = 5;
    
    TypeInfo<int> c(a);
    
    c.ShowTypeName();
    
    return 0;
}

