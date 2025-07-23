//
//  main.cpp
//  copy constructor
//
//  Created by mac on 16.01.25.
//

#include <iostream>

using namespace std;

class MyClass{
public:
    int *data;     //сделаем через динамическое выделение памяти
    
    MyClass(int size){
        this -> Size = size;
        
        this -> data = new int[size];     //обычный одномерный динамический массив
        
        for(int i = 0; i < size; i++){
            data[i] = i;
        }
        
        cout<< "Вызвался конструктор "<< this << endl;
    }
    
    MyClass(const MyClass &other){   //конструктор копирования, в параметр принимаем константу, так как в том объекте, который мы копируем мы ничего не изменяем
        this -> Size = other.Size;
        
        this -> data = new int[other.Size];
        
        for(int i = 0; i < other.Size; i++){
            this -> data[i] = other.data[i];
        }
        
        cout<< "Вызвался конструктор копирования "<< this << endl;
    }
    
    
    ~MyClass(){
        
        cout<< "Вызвался деструктор "<< this << endl;
        
        delete[] data;   //удаляем динамический массив
    }
    
private:
    int Size;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    MyClass a(10);
    MyClass b(a);
    
    return 0;
}
