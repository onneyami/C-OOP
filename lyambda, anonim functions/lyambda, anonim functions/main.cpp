#include <iostream>
#include <functional>

using namespace std;

//лямбда выражения, лямбда функция, анонимные функции

void Foo(int a){if(a > 10 && a < 40){cout << a << endl;}}

int Sum(int a, int b){return a + b;}

void Bar(int a){if(a % 2 == 0){cout << a << endl;}}

void DoWork(vector<int> &vc, vector<function<void(int)>> FunctionsVector){for(auto el : vc){for(auto &fel : FunctionsVector){fel(el);}}}

void DoWork_1(vector<int> &vc, function<void(int)> f)
{
    for(auto el : vc)
    {
        f(el);
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    
    int p = 0;
    
    //в 14 стандарте появилась возможность определять function<type(members)> просто через auto
    
    auto f = [&p](){    //чтобы передать из внешнего контекта к примеру переменную p по ссылке, указываем ее в квадратных скобках анонимной функции
      p = 5;
    };
    
    f();
    
    vector<int> vc = {1, 51, 4, 23, 82, 172, 64, 2, 7};
    
    /*function<void(int)> f;
    
    f = [](int a) {     //синтаксис анонимной функции
        cout << "Вызваная анонимная функция с параметром " << a << endl;
    };
    
    DoWork_1(vc, f);*/     //можно делать так, но это долгий путь, поэтому просто передаем весь синтаксис анонимной функции в вызов функции DoWork_1 вторым параметром:
    
    DoWork_1(vc, [](int a){cout << "Вызваная анонимная функция с параметром " << a << endl;});
    
    auto f_1 = [](){
        return 1;       //в зависимости от того, какой тип данных мы вернем определяется тип возвращаемых значений у лямбда функции, в нашем случае будет int
    };
    
    auto q = f_1();
    
    return 0;
}

//используются анонимные функции опять же, чтобы не захламлять код

