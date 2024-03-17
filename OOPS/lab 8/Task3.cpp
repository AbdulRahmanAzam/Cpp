// Multiple inheritance

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Position{
    public:
    int x,
    y,
    z;
    
    Position(int x, int y, int z) : x(x), y(y), z(z) {}
    
    void display(){
        cout << "Position = " << x << " " << y << " " << z << endl;
    } 
    
};

class Health{
    public:
    int health;
    
    Health(int health) : health(health) {}
    void display(){
        cout << "health = " << health << endl;
    }
};

class Character : public Position, public Health{
    public:
    string name;
    int age;
    int power;
    
    Character(string name, int age, int power, int health, int x, int y, int z) : name(name), age(age), power(power), Health(health), Position(x,y,z) {}
    
    void display(){
        Position::display();
        Health::display();
        cout << "name = " << name
        << "\nage = " << age
        << "\npower = " << power << endl;
    }
};

int main(){
    Character c1("Abdul Rahman Azam", 19, 100, 60, 2,4,8);
    c1.display();
}
