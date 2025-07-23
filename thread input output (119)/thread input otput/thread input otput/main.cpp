#include <iostream>
#include <string>
#include <fstream>


using namespace std;

//Потоковый ввод вывод в файл c++. Перегрузка операторов >> и <<

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
private:
    int x;
    int y;
    int z;
    
    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is, Point& point);
};

ostream& operator<<(ostream& os, const Point& point){   //второй параметр - это класс, для которого выполняем перегрузку оператора, первый параметр ostream это cout, который мы прописываем перед <<
    
    os << point.x << " " << point.y << " " << point.z << endl;
    
    return os;
}

istream& operator>>(istream& is, Point& point){  //так как мы будем считывать и изменять данные, то const не указываем в отличии от ostream <<
    
    is >> point.x >> point.y >> point.z;
    
    return is;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    string path = "myfile.txt";
    
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    
    if(!fs.is_open()){
        cout << "Ошибка открытия файла!" << endl;
    }
    else{
        cout << "Файл открыт" << endl;
       // fs << p << "\n";     //записываем данные объекта p класса point в файл
        
        while(true){
            
            Point p;
            fs >> p;    //считываем данные из файла в объект класса
            
            if(fs.eof()){   //когда конец файла - конец
                break;
            }
            
            cout << p << endl;
            
        }
    }
    
    fs.close();
    
    return 0;
}


