#include <iostream>
#include <string>

using namespace std;

//Вложенные классы с++ пример. Внутренние классы. Зачем нужны.

// тот класс, в который вкладываем называется объемлющий класс

class Image{
public:
    
    void GetImageInfo(){
        for(int i = 0; i < length; i++){
            cout << "Number " << i << " " << pixels[i].GetInfo() << endl;
        }
    }
    
private:
    class Pixel{
    public:
        Pixel(int r, int g, int b){
            this -> r = r;
            this -> g = g;
            this -> b = b;
        }
        
        string GetInfo(){
            return "Pixel: r=" + to_string(r) + " g="+to_string(g) + " b="+to_string(b);
        }
        
    private:
        int r;
        int g;
        int b;
    };
    
    const int length = 5;
    
    Pixel pixels[5]{      //массив пикселей в private секции у класса Image
        Pixel(0,4,5),
        Pixel(3,6,9),
        Pixel(3,8,5),
        Pixel(9,1,0),
        Pixel(0,5,1)
    };
    
};

int main() {
    setlocale(LC_ALL, "RU");
    
    Image img;
    img.GetImageInfo();
    
    return 0;
}

//вложенные классы используются тогда, когда есть класс с таким же названием, чтобы компилятор не запутался
