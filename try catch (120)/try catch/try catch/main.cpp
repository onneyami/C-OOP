#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//С++ try catch. Обработка исключений С++. try catch что это

int main() {
    setlocale(LC_ALL, "RU");
    
    string path = "MyFile.txt";
    
    ifstream fin;
    
    fin.exceptions(ifstream::badbit | ifstream::failbit);  //подключаем для обработки исключений, специфика только для ifstream
    
    try {
        cout << "Попытка открыть файл!" << endl;
        fin.open(path);
        cout << "Файл успешно открыт!" << endl;
        
    }
    catch (const ifstream::failure & ex)   //ifstream::failure - это класс exception именно для ошибок ифстрима, позволяет получать более широкую информацию о более узких ошибках
    {
        cout << ex.what() << endl;   //вывод на консоль, в чем именно ошибка
        cout << ex.code() << endl;   //вывод на консоль, в чем ошибка для более узких ошибок, более конкретное пояснение, такая информация будет в разы полезнее именно для разработчика, потому что получаем код ошибки
        cout << "Ошибка открытия файла!" << endl;
    }
    
    
    return 0;
}
