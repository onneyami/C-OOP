#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Перечисляемый тип enum

//enum - это по сути tool для разработчика, так как позволяет работать с более понятным кодом, вместо цифр как в нашем примере

class PC{
public:
    
    enum PCState{    //enum можно прописывать прямо внутри класса, если он используется только для этого класса
        OFF,
        ON,
        Sleep
    };
    
    PCState GetState(){ return State; }
    void SetState(PCState State){ this -> State = State; }
    
private:
    PCState State;
};

enum Speed{    //в случае с enum для pcstate нам хватит базовых цифр, по типу 0 1 и 2 и так далее, но в случае со скоростью для самолета к примеру, мы уже сами можем задавать минимальную рекомендованную и максимальную скорость числовыми значениями
  MIN = 150,
    RECOMMEND = 600,
    MAX = 800
};

int main() {
    setlocale(LC_ALL, "RU");
    
    PC pc;
    pc.SetState(PC::ON);
    
    //if(pc.GetState() == ON){
    //    cout << "PC is ON" << endl;
    //}
    
    switch (pc.GetState()) {
        case PC::OFF:
            cout << "PC is OFF" << endl;
            break;
        case PC::ON:
            cout << "PC is ON" << endl;
            break;
        case PC::Sleep:
            cout << "PC is in sleep mode" << endl;
            break;
        default:
            break;
    }
    
    
    
    return 0;
}
