#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Vehicle{
    public:
    string make;
    int model;
    int year;
    
    Vehicle(string make, int model, int year) : make(make), model(model), year(year) {}
    
    void display(){
        cout << "make = " << make
        << "\nmodel = " << model
        << "\nyear = " << year << endl;
    }
};

class Car : public Vehicle{
    public:
    int doors;
    int fuel;
    int efficiency;
    
    Car(string make, int model, int year, int doors, int fuel, int efficiency) :Vehicle(make,model,year), doors(doors), fuel(fuel), efficiency(efficiency) {}
    
    void display(){
        cout << "doors = " << doors
        << "\nfuel = " << fuel
        << "\nefficiency = " << efficiency << endl;
    }
};

class ElectricCar : public Car{
    public:
    int battery_life;
    
    ElectricCar(string make, int model, int year, int doors, int fuel, int efficiency, int battery_life) : Car(make, model, year, doors, fuel, efficiency),  battery_life(battery_life) {};
    
    void display(){
        Vehicle::display();
        Car::display();
        cout << "battery life = " << battery_life << endl;
    }
};

int main(){
    ElectricCar c1("toyota", 2016, 2023, 5, 60, 85, 700);
    c1.display();
}
