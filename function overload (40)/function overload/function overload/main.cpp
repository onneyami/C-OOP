#include <iostream>

using namespace std;

//перегрузка функций

int Sum(int a, int b){
    return a + b;
}

double Sum(double a, double b){
    return a + b;
}

int Sum(int a, int b, int c){
    return a + b + c;
}

//таким образом у одной функции есть больше, чем одна реализация -> перегрузка функции

int main(){
    setlocale(LC_ALL, "RU");
    
    Sum(1.3f,2.6f);
    Sum(1,2);
    Sum(3,6,1);
    
    return 0;
}
