#include <iostream>
#include <string>

using namespace std;

//Наследование в ООП пример. Что такое наследование. Для чего нужно наследование классов

class Human{
private:
    string name;
public:
    
    string GetName(){
        return name;
    }
    
    void SetName(string name){
        this -> name = name;
    }
};

class Student : public Human{       //здесь показываем, что наследуемся от класса Human
public:
    string group;
    
    void Learn(){
        cout << "Я учусь! " << endl;
    }
};

class Professor : public Human{
public:
    string subject;
};

class ExtramuralStudent: public Student {
public:
    void Learn(){
        cout << "Я бываю в университете реже обычного студента!" << endl;
    }
    
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Student st;
    st.GetName();
    
    ExtramuralStudent exst;
    exst.Learn();
    
    return 0;
}

//при НЕ наследовании невозможно применить полиморфизм, а также невозможно хранить разные классы в одной коллекции (массиве)
