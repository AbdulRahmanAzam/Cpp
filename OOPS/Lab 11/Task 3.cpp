#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Vehicle{
    string make;
    string model;
    int speed;

    public:
    Vehicle(string make, string model, int speed) : make(make), model(model), speed(speed) {}
    virtual ~Vehicle() = default;

    string getMake(){
        return this->make;
    }
    string getModel(){
        return this->model;
    }
    int getSpeed(){
        return this->speed;
    }

    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;
};

class Car : public Vehicle {
    double fuelCapacity;

    public:
    Car(double fuelCapacity, string make, string model, int speed) : 
    Vehicle(make, model, speed), fuelCapacity(fuelCapacity) {}
    virtual ~Car() = default;

    void accelerate() override {
        cout << "CAR accelerates" << endl;
    }
    void brake() override {
        cout << "Brakes are applied in CAR" << endl;
    }
    void calculateFuelEfficiency() override {
        cout << "The fuel efficiency of CAR is 21 km/litre" << endl;
    }
};
class Truck : public Vehicle{
    int cargoCapacity;

    public:
    Truck(int cargoCapacity, string make, string model, int speed) : 
    Vehicle(make, model, speed), cargoCapacity(cargoCapacity) {}
    virtual ~Truck() = default;

    void accelerate() override {
        cout << "TRUCK accelerates" << endl;
    }
    void brake() override {
        cout << "Brakes are applied in TRUCK" << endl;
    }
    void calculateFuelEfficiency() override {
        cout << "The fuel efficiency of TRUCK is 21 km/litre" << endl;
    }
};

int main(){
    Car car(4500.0, "Honda", "2004", 260);
    Truck truck(1000, "Mercedes", "2024", 180);

    car.accelerate();
    car.brake();
    car.calculateFuelEfficiency();

    cout << endl;

    truck.accelerate();
    truck.brake();
    truck.calculateFuelEfficiency();
}
