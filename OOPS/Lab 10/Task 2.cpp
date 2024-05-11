
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Num{

    public:
    int num;
    Num(int num) : num(num) {}

    Num& operator--(){
        this->num *= 4;
        return *this;
    }
    Num& operator--(int){
        this->num /= 4;
        return *this;
    }

};

int main(){
    Num a(5);
    a--;
    cout << " a-- = " << a.num << endl;

    a.num = 5;

    --a;
    cout << "--a = " << a.num << endl;
 }
