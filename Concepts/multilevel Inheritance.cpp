// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class student{
    protected: 
    int roll;
    
    public:
    void get_number(int a){
        roll = a;
    }
    void put_number(){
        cout << "ROll numbner " << roll << endl;
    }
};

class test : public student{     // first level derivation
    protected:
    float sub1;
    float sub2;
    
    public:
    void get_marks(float x, float y){
        sub1 = x;
        sub2 = y;
    }
    void put_marks(){
        cout << "marks in sub1 " << sub1 << endl << "marks in sub2 " << sub2 << endl;
    }
};

class result : public test{     // second level derivation
    float total;
    
    public:
    void display(void){
        total = sub1 + sub2;
        put_number();
        put_marks();
        cout << "total = " << total << endl;
    }
};

int main(){
    result stud;
    stud.get_number(111);
    stud.get_marks(75.0, 59.5);
    stud.display();
    
}
