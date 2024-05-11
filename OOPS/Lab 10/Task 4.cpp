#include <iostream>
using namespace std;

class Perimeter {
private:
    float length;
    float breadth;

public:
    Perimeter(float l, float b) : length(l), breadth(b) {}
    friend class PrintClass;
};

class PrintClass {
public:
    void displayPerimeter(Perimeter& obj) const {
        float perimeter = 2 * (obj.length + obj.breadth);
        cout << "Perimeter: " << perimeter << endl;
    }
};

int main() {
    Perimeter rectangle(5.0, 4.0);

    PrintClass printer;
    printer.displayPerimeter(rectangle);

    return 0;
}
