#include <iostream>
#include <string>

using namespace std;

//c++ вызов виртуального метода базового класса

class Msg{
public:
    Msg(string msg){
        this -> msg = msg;
    }
    
    virtual string GetMsg(){
        return msg;
    }
    
private:
    string msg;
};

class BraketsMsg : public Msg{
public:
    BraketsMsg(string msg):Msg(msg){
        
    }
    
    string GetMsg () override{
        return "[" + ::Msg::GetMsg() + "]";    //чтобы метод бесконечно не вызывал сам себя, нужно указать в нашем случае ::Msg::, чтобы явно указать компилятору, что мы внутри переопределенного метода класса-наследника вызываем именно метод у класса-родителя
    }
    
};

class Printer{
public:
    void Print(Msg *msg){
        cout << msg -> GetMsg() << endl;
    }
};

int main(){
    setlocale(LC_ALL, "RU");
    
    BraketsMsg b("Привет!");
    
    Printer M6500;
    M6500.Print(&b);
    return 0;
}
