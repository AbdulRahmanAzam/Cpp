#include <iostream>
using namespace std;

class ABC;

class XYZ{
    int data;
    
    public:
    void setvalue(int value){
        data = value;
    }
    friend void add(XYZ, ABC);
    friend void exchange(XYZ &, ABC &);
    friend void display(XYZ, ABC);
};
class ABC{
    int data;
    
    public:
    void setvalue(int value){
        data = value;
    }
    friend void add(XYZ, ABC);
    friend void exchange(XYZ &, ABC &);
    friend void display(XYZ, ABC);
};
void add(XYZ a, ABC b){
    cout << "XYZ and ABC are using friend function =  " << a.data + b.data << endl;
}
void exchange(XYZ & a, ABC & b){
    swap(a.data, b.data);
}
void display(XYZ a, ABC b){
    cout << "a = " << a.data << "  b = " << b.data << endl;
}

int main(){
    XYZ a;
    ABC b;
    
    a.setvalue(10);
    b.setvalue(20);
    
    add(a, b);
    display(a,b);
    exchange(a,b);
    display(a,b);
    return 0;
}
