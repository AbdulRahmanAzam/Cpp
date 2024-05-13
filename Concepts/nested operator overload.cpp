#include <iostream>
using namespace std;

class Num{
    int num;
    public:
    Num(int num) : num(num) {}

    Num operator+(const Num& other){
        cout << "operator + is called" << endl;
        // return Num(num + 1);
        return Num(num + other.num);
    }

    Num operator-(const Num& other){
        cout << "operator - is called" << endl;
        // calls + overloaded operator
        // making this to (*this) - other will end up in infinite loops
        return (*this) + other;
    }

    Num& operator=(const Num& other){
        cout << "operator = is called" << endl;
        // calls + overloaded operator
        (*this) + other;
        // calls - overloaded operator
        (*this) - other;
        return *this;
    }
};

int main(){
    Num a(4), b(3);
    a = b;
}
