//
//  main.cpp
//  smartpointers
//
//  Created by mac on 15.01.25.
//

#include <iostream>

using namespace std;

template<typename T>     //прописываем для того, чтобы класс SmartPointer мог работать с любым типом данных, так как сам тип данных T - это любой тип данных
class SmartPointer{
public:
    
    SmartPointer(T *ptr){     //конструктор
        this->ptr = ptr;      //записываем получаемый указатель в private
        cout<< "Constructor"<< endl;
    }
    
    ~SmartPointer(){           //деструктор
        delete ptr;            //очищаем память, на которую указывает данный указатель
        cout<< "Destructor"<< endl;
    }
    
    //деструктор будет вызван автоматически при уничтожении объекта класса
    
    T& operator*(){      //перегруженная функция
        return *ptr;    //разыминование указателя, чтобы получать не адрес памяти, а данные по адресу памяти
    }
    
private:
    T *ptr;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    // если через обычный указатель, пример:
    int *ptr = new int(5);
    delete ptr;
    
    //умные указатели используем, чтобы не следить, где нужно выделить, а где очистить память и заменить это на автоматику
    
    //пример через умный указатель:
    SmartPointer<int> pointer = new int(5);
    
    //после этого не нужно заботиться о очищении памяти, так как при уничтожении память очищается автоматически
    
    cout<< *pointer << endl;     //вывод разыминованого умного указателя, то-есть 5
    
    return 0;
}
