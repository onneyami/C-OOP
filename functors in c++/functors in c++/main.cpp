#include <iostream>

using namespace std;

//функторы в с++, что такое функтор

class MyFunctor{
public:
    /*void operator ()(){    //перегружаем оператор ()
        cout << "я функтор " << count << endl;
        count++;
    }*/
    
    int operator ()(int a, int b){
        return a + b;
    }
    
private:
    int count = 0;
};

class EvenFunctor{
public:
    
    void operator ()(int a){
        if(a % 2 == 0){
            EvenSum+=a;
            EvenCount++;
        }
    }
    
    void ShowEvenCount(){
        cout << "Even count is " << EvenCount << endl;
    }
    
    void ShowEvenSum(){
        cout << "Even sum is " << EvenSum << endl;
    }
    
private:
    int EvenCount = 0;
    int EvenSum = 0;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    MyFunctor mf;
    auto result = mf(2,5);
    
    int array[5] = {1, 2, 3, 4, 5};
    EvenFunctor ev;
    
    for(auto el : array){
        ev(el);
    }
    
    ev.ShowEvenCount();
    ev.ShowEvenSum();
    
    return 0;
}

//функторы - это классы, у которых перегружен оператор () -> объекты класса могут вести себя как функции, но при этом могут хранить состояние данных
