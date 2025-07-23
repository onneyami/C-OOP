#include <iostream>
#include <string>
#include <fstream>


using namespace std;

//Чтение и запись в файл с++ используя класс fstream c++

class Point{
public:
    Point(){
        x = y = z = 0;
    }
    
    Point(int x, int y, int z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    
    void Print(){
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
        cout << "Z: " << z << endl;
    }
    
    int x;
    int y;
    int z;
};

int main() {
    setlocale(LC_ALL, "RU");
    
    string path = "myfile.txt";
    
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);     //параметр in указывает на то, что мы имеем возможность открывать файл для чтения, затем через битовое "или" параметр out указывает на то, что мы имеем возможность записывать данные в файл, затем app - при новой записи старая не стирается
    
    if(!fs.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }else{
        string msg; //грубо говоря буфер, в котором будем хранить сообщение при вводе и сохранении
        
        int value;
        
        cout << "Файл открыт" << endl;
        cout << "Введите 1 для записи сообщения в файл" << endl;
        cout << "Введите 2 для считывания всех сообщений из файла" << endl;
        
        m: cin >> value;
        
        switch (value) {
            case 1:
                cout << "Введите сообщение для записи в файл: ";
                cin >> msg;
                fs << msg << "\n";
                break;
                
            case 2:
                cout << "Полученные данные из файла:" << endl;
                while(!fs.eof()){    //пока не закончится файл
                    msg = "";     //затираем чтоб не было дубляжа
                    fs >> msg;
                    cout << msg << endl;
                }
                break;
                
            default:
                cout << "Некорректный выбор функции! Попробуйте еще раз!" << endl;
                goto m;
                break;
        }
    }
    
    fs.close();
    
    return 0;
}

