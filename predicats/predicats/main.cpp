#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Предикаты

//задача предиката ответить на вопрос да или нет в зависимости от его реализации нами

bool GreaterThanZero(int a){    //простейший предикат, который отвечает больше ли переменная чем 0
    return a > 0;
}

bool LessThanZero(int a){
    return a < 0;
}

class Person
{
public:
    Person(string name, double score){
        this->Name = name;
        this->Score = score;
    }
    
    bool operator()(const Person &p){      //функтор одновременно и предикат
        return p.Score > 180;
    }
    
private:
    string Name;
    double Score;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    vector<int> v = {1, -2, -55, 9, -3, 8};
    
    //GreaterThanZero(1);   //будет true -> в выводе будет 1
    
    auto result = count_if(v.begin(),v.end(), GreaterThanZero);    //вместо всяких циклов с if else в реальных проектах используют данный алгоритм STL, принимает начало и конец коллекции и предикат, по которому будет проверять элементы и подсчитывать
    
    cout << result << endl;
    
    auto result_1 = count_if(v.begin(),v.end(), LessThanZero);
    
    cout << result_1 << endl;
    
    vector<Person> people
    {
        Person("Вася", 181),
        Person("Петя", 30),
        Person("Маша", 179)
    };
    
    auto result_2 = count_if(people.begin(), people.end(), people.front());     //передаем в предикат метод фронт, так как внутри класса есть функтор-предикат
    
    return 0;
}

//наиболее частое применение предикатов - это с алгоритмами STL
