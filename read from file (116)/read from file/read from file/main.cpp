#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Работа с файлами с++. Чтение из файла с++ ifstream

//ifstream - input file stream - чтение из файла

int main() {
    setlocale(LC_ALL, "RU");
    
    string path = "myfile.txt";
    
    ifstream inputfile;
    inputfile.open(path);
    
    if(!inputfile.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else{
        cout << "Файл открыт." << endl;
        char ch;
        
        while(inputfile.get(ch)){      //такая реализация выводит на экран поочередно по одному символу из нашего файла
            cout << ch;
        }
           //метод get "вытягивает" по одному символу из файла
        
        string str;
        while(!inputfile.eof()){     //.eof() "отлавливает" конец файла, следовательно такая реализация поочередно по строке выводит на экран из нашего файла
            str = "";    //в начале каждой итерации очищаем значение str, чтобы избежать дублежа
            getline(inputfile,str);   //этот метод берет значение из inputfile и записывает в str, при этом пропускает пробелы
            cout << str << endl;
        }
    }
     
    inputfile.close();
    
    return 0;
}
