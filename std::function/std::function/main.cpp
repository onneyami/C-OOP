#include <iostream>
#include <functional>

using namespace std;

//std::function - полиморфная обертка функции

void Foo(int a){
    if(a > 10 && a < 40){
        cout << a << endl;
    }
}

int Sum(int a, int b){
    return a + b;
}

void Bar(int a){
    if(a % 2 == 0){
        cout << a << endl;
    }
}

void DoWork(vector<int> &vc, vector<function<void(int)>> FunctionsVector){    //передаем вместо определенной функции function, благодаря этому мы при вызове функции DoWork для какого-либо вектора указываем функцию, через которую он будет работать, чтобы не переписывать данную функцию DoWork ради изменения одной строчки кода
    
    //для использования разных функций и опять же, чтобы избежать дублирования можно к примеру использовать вектор таких функций и передать в него наш function, но, нужно будет добавить еще один цикл, который будет перебирать функции этого вектора
    for(auto el : vc){
        for(auto &fel : FunctionsVector){
            fel(el);
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    
    function<void(int)> f;    //при создании объекта function в угловых скобках указываем тип возвращаемого значения (по сути тип функции) и в круглых скобках указываем кол-во элементов, которые функции для которых мы создаем этот объект будут принимать
    
    f = Foo;
    f(5);    //по сути оператор вызова хранимой в нем функции
    
    function<int(int,int)> f_1;
    f_1 = Sum;
    int result = f_1(5,2);
    cout << result << endl;
    
    vector<int> vc = {1,6, 12, 78, 662, 16, 93};
    
    vector<function<void(int)>> fvc;
    
    fvc.emplace_back(Foo);
    fvc.emplace_back(Bar);
    
    DoWork(vc, fvc);
    
    return 0;
}

//по сути это аналог указателя на функцию, но только из мира ООП
