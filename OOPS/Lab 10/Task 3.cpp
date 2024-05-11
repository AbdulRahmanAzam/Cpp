#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Shape{
    int area;

    public:
    Shape(int area) : area(area) {}
    Shape() : area(0) {}

    Shape operator+(Shape shape2){
        return this->area + shape2.area;
    }

    int Area(){
        return this->area;
    }
};

int main(){
    Shape shape1(5), shape2(10), shape3;

    shape3 = shape1 + shape2;
    cout << " shape 3 = " << shape3.Area() << endl;
}
