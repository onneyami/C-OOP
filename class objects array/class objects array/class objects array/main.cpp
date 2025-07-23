#include <iostream>
#include <string>

using namespace std;

//Массив объектов класса. Динамический. Статический. Создание Особенности.

class Pixel{
    public:
        
    Pixel(){
        r = 0;
        g = 0;
        b = 0;
    }
    
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
    
int main() {
    setlocale(LC_ALL, "RU");
    
    const int length = 5;
    
    //Pixel p(4, 11, 83);
    
    Pixel arr[length];
    
    arr[0] = Pixel(11, 11, 11);
    
    arr[0].GetInfo();
    
    //Пример динамического массива объектов класса, получается тоже самое, что и с обычными элементами
    Pixel *arr_1 = new Pixel[length];
    
    delete[] arr_1;
    
    return 0;
}


