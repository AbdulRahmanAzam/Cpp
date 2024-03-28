#include <iostream>
using namespace std;

class Shape{
    public:
    virtual double area() const{
        return 0;
    }

    virtual double perimeter() const{
        return 0;
    }

    virtual void displayProperties() const{
        return;
    }
};

class Circle : public Shape {
    double r;
    public:
    
    Circle() {
        cout << "Enter the radius of the Circle" << endl;
        cin >> this->r;
    }
    virtual double area() const{
        return (3.14 * r * r);
    }

    virtual double perimeter() const{
        return (2 * 3.14 * r);
    }

    virtual void displayProperties() const{
        cout << "Properties of Circle" << endl;
        cout << "-Area = " << area() << endl
        << "-Perimeter = " << perimeter() << endl
        << "-Diameter = " << 2*r << endl;
    }
};

class Rectangle : public Shape{
    double length, width;
    public:
    Rectangle() {
        cout << "Enter the length of the rectangle" << endl;
        cin >> this->length;
        cout << "Enter the width of the rectangle" << endl;
        cin >> this->width;
    }

    virtual double area() const{
        return (length * width);
    }

    virtual double perimeter() const{
        return (length*2) + (width *2);
    }

    virtual void displayProperties() const{
        cout << "Properties of Rectangle" << endl;
        cout << "-Area = " << area() << endl
        << "-Perimeter = " << perimeter() << endl
        << "-Diagonal = " << sqrt((width*width) + (length*length)) << endl;
        return;
    }
};

class Square : public Shape{
    public:
    double side;
    Square(){
        cout << "Enter the side of the Square" << endl;
        cin >> this->side;
    }
    virtual double area() const{
        return (side * side);
    }

    virtual double perimeter() const{
        return (side*4);
    }

    virtual void displayProperties() const{
        cout << "Properties of Square" << endl;
        cout << "-Area = " << area() << endl
        << "-Perimeter = " << perimeter() << endl
        << "-Diagonal = " << side * sqrt(2) << endl;
    }
};

class Triangle : public Shape{
    public:
    double s1, s2, s3;
    Triangle() {
        cout << "Enter the lengths of the three sides of the triangle" << endl;
        cin >> this->s1 >> this->s2 >> this->s3;
    }
    virtual double area() const{
        double s = (s1 + s2 + s3) /3;
        return sqrt(s * (s-s1) * (s-s2)*(s-s3));
    }

    virtual double perimeter() const{
        return (s1 + s2 + s3);
    }

    virtual void displayProperties() const{
        cout << "Properties of Triangle" << endl;
        cout << "-Area = " << area() << endl
        << "-Perimeter = " << perimeter() << endl;
    }
};

class EquilateralTriangle : public Triangle{
    public:
    double s;
    EquilateralTriangle() {
        cout << "Enter the side of Equilateral triangle" << endl;
        cin >> this->s;
    }

    virtual double area() const{
        return (sqrt(3)/4 * (s*s));
    }

    virtual double perimeter() const{
        return (3 * s);
    }

    virtual void displayProperties() const{
        cout << "Properties of equilateral Triangle" << endl;
        cout << "-Area = " << area() << endl;
    }
};



int main(){
    cout << "Welcome to the Geometry Competition calculator" << endl;
    int n; 
    string cont;
    bool check;
    do{
        cout << "Please select a shape";
        cout << "1. Circle" << endl
        << "2. Rectangle " << endl
        << "3. Square " << endl
        << "4. Triangle" << endl;

        cout << "Enter your choice: ";
        cin >> n;

        switch(n){
            case 1:
                Circle c;
                c.displayProperties();
            
            case 2:
                Rectangle r();

            case 3:
                Square sq();

            case 4:
                Triangle tri();
        }

        cout << "Do you want to calculate properties for another shape? (yes/no) : " << endl;
        cin >> cont;
        check = (cont == "yes") ? 1 : 0;
    }while(check); 
}
