//
//  main.cpp
//  function overload
//
//  Created by mac on 16.01.25.
//

// Перегрузка оператора присваивания на основе прошлого урока по конструктору копирования

#include <iostream>

using namespace std;

class MyClass{
public:
    int *data;     //сделаем через динамическое выделение памяти
    
    MyClass(int size){
        this->Size = size;
        
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
    
    MyClass & operator = (const MyClass &other){
        this -> Size = other.Size;
        cout<< "Вызвался оператор = "<< this << endl;
        
        
        if(this -> data != nullptr){      //проверка на nullptr
            delete[] this -> data;
            }
        
        this -> data = new int[other.Size];     //обычный одномерный динамический массив
        
        for(int i = 0; i < other.Size; i++){
            this -> data[i] = other.data[i];
        }
        
        return *this;   //возвращаем адрес константного указателя, всё это делается для того, чтобы работало a = b = c;
    }

    
    
    ~MyClass(){     //деструктор
        
        cout<< "Вызвался деструктор "<< this << endl;
        
        delete[] data;   //удаляем динамический массив
    }
    
private:
    int Size;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    MyClass a(10);
    MyClass b(a);     //вызовется не оператор присваивания, а конструктор копирования, так как объект еще не инициализирован
    a = b;    //после добавления перегруженного оператора присваивания у этих объектов будут разные адреса, а не один, адреса массивов тоже разные, следовательно деструктор вызовется для каждой ячейки памяти, а не для одной и соответственно ошибки на выходе не будет
    
    return 0;
}
