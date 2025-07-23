#include <iostream>
#include <thread>     //вместе с thread подключается автоматически библиотека chrono
//#include <chrono>
 
using namespace std;

//как измерить время выполнения кода

class SimpleTimer{     //класс для подсчета времени, будет автоматически подсчитывать
public:
    
    SimpleTimer(){
        start = std::chrono::high_resolution_clock::now();
    }
    
    ~SimpleTimer(){
        end = std::chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        cout << "Duration in seconds is: " << duration.count() << endl;
    }
    
private:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
};

int Sum(int a, int b){
    return a + b;
}

int main() {
    setlocale(LC_ALL, "RU");
    
    SimpleTimer st;
    
    int result;
    
    thread t([&result]() { result = Sum(5,2); } );
    
    //auto start = chrono::high_resolution_clock::now();   //возвращает текущую точку во времени
    for(size_t i = 1; i <= 10; i++){
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "ID потока: " << this_thread::get_id() << endl;
        cout << "MAIN WORKS" << endl;
    }
    //auto end = chrono::high_resolution_clock::now();   //возвращает текущую точку во времени
    
    //chrono::duration<float> duration = end - start;
    //cout << "Duration is: " << duration.count() << endl;
    
    t.join();
    cout << "Sum result: " << result << endl;
    
    return 0;
}
