#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Пространства имен. Namespace что это

//неймспейсы применяются в случаях по типу: в компании два программистра работают над двумя разными областями кода, но описывают функцию с одним именем

namespace firstNS{
   void Foo(){
       cout << "First foo" << endl;
   }
}

namespace secondNS{
   void Foo(){
       cout << "Second foo" << endl;
   }
}

int main() {
    setlocale(LC_ALL, "RU");
    
    secondNS::Foo();
    
    return 0;
}
