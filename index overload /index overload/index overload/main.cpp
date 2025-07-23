#include <iostream>
#include <string>

using namespace std;

//Перегрузка оператора индексирования . Перегрузка операторов пример. C++ Для начинающих.
class Human{
public:
    string name;
    int age;
    int weight;
    
    void GetInfo(){
        cout<< "The name is "<< name << endl;
        cout<< "The age is "<< age << endl;
        cout<< "The weight is "<< weight << endl;
    }
};

class Point{
private:
    float x;
    float y = 3.67f;

public:
    
    Point(){
        x = 0;
        y = 0;
        cout<< this << " Constructor" << endl;
    }
    
    Point (float valueX, float valueY){
        x = valueX;
        y = valueY;
        cout<< this << " Constructor" << endl;
    }
    
    bool operator ==(const Point & other){
        return this -> x == other.x && this -> y == other.y;
        }
    
    bool operator !=(const Point & other){
        return !(this -> x == other.x && this -> y == other.y);
    }
    
    Point operator +(const Point & other){
        Point temp;
        temp.x = this -> x + other.x;
        temp.y = this -> y + other.y;
        return temp;
    }
    
    
    float GetX (){
        return x;
    }
    
    float GetY (){
        return y;
    }
    
    void SetX (float valueX){
        x = valueX;
    }
    
    void SetY (float valueY){
        y = valueY;
    }
    
    Point & operator++(){
        this -> x++;
        this -> y++;
        return *this;
    }
    
    Point & operator++(int value){
        Point temp(*this);
        
        this -> x++;
        this -> y++;
        
        return temp;
    }
    
    Point & operator--(){
        this -> x--;
        this -> y--;
        return *this;
    }
    
    Point & operator--(int value){
        Point temp(*this);
        
        this -> x--;
        this -> y--;
        
        return temp;
    }
    
    void Print(){
        cout<< "X is "<< x << endl;
        cout<< "Y is "<< y << endl;
    }
    
    };

class CoffeGrinder{
private:
    
    bool CheckVoltage(){
        return true;
    }
    
public:
    void Start(){
        if(CheckVoltage() == true){
            cout << "CoffeGrinder is ON" << endl;
        }
        else {
            cout << "CoffeGrinder is OFF, check the voltage." << endl;
        }
    }
};

class MyClass{
public:
    int *data;
    
    MyClass(int size){
        this->Size = size;
        
        this -> data = new int[size];
        
        for(int i = 0; i < size; i++){
            data[i] = i;
        }
        
        cout<< "Вызвался конструктор "<< this << endl;
    }
    
    MyClass(const MyClass &other){
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
        
        
        if(this -> data != nullptr){
            delete[] this -> data;
            }
        
        this -> data = new int[other.Size];
        
        for(int i = 0; i < other.Size; i++){
            this -> data[i] = other.data[i];
        }
        
        return *this;
    }

    
    
    ~MyClass(){
        
        cout<< "Вызвался деструктор "<< this << endl;
        
        delete[] data;
    }
    
private:
    int Size;
};

class TestClass{
public:
    
    int & operator[](int index){      //перегрузка оператора индексирования, если хотим сделать так, чтобы ничего нельзя было менять, то нужно убрать &, иначе же мы возвращаем ссылку на данный объект и менять его можно
        return array[index];
    }
    
    // так как мы не можем напрямую достать элемент массива из private секции, то делаем это через перегруженный оператор индексирования
    
private:
    int array[5] = {1, 2, 3, 4, 5};
};

int main() {
    setlocale(LC_ALL, "RU");
    
    TestClass a;
    a[3] = 100;
    cout<< a[3] << endl;
    
    return 0;
}







