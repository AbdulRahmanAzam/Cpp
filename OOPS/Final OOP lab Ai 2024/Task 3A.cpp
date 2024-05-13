#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Vehicle{
    string make;
    string model;
    int maxSpeed;


    public:
    Vehicle(string make, string model, int maxSpeed) : make(make), model(model), maxSpeed(maxSpeed) {}

    string getMake(){
        return this->make;
    }
    string getModel(){
        return this->model;
    }
    int getMaxSpeed(){
        return this->maxSpeed;
    }
};

class Bus : public Vehicle{
    int numSeats;
    string routes;

    public:
    Bus(string make, string model, int maxSpeed, int numSeats, string routes) :
    Vehicle(make, model, maxSpeed), numSeats(numSeats), routes(routes) {}

    int getNumSeats(){
        return this->numSeats;
    }
    string getRoute(){
        return this->routes;
    }
};

class Train : public Vehicle{
    int numSeats;
    string routes;

    public:
    Train(string make, string model, int maxSpeed, int numSeats, string routes) :
    Vehicle(make, model, maxSpeed), numSeats(numSeats), routes(routes) {}

    int getNumSeats(){
        return this->numSeats;
    }
    string getRoute(){
        return this->routes;
    }
};

class Airplane : public Vehicle{
    int numSeats;
    int altitude;

    public:
    Airplane(string make, string model, int maxSpeed, int numSeats, int altitude) :
    Vehicle(make, model, maxSpeed), numSeats(numSeats), altitude(altitude) {}

    int getNumSeats(){
        return this->numSeats;
    }
    int getAltitude(){
        return this->altitude;
    }
};

template <typename T>
class BookingSystem{
    T vehicle;
    string departureTime;
    string arrivalTime;
    double cost;

    public:
    BookingSystem(T vehicle, string departureTime, string arrivalTime, double cost) : 
    vehicle(vehicle), departureTime(departureTime), arrivalTime(arrivalTime), cost(cost) {}

    Vehicle getVehicle(){
        return this->vehicle;
    }
    string getDepartureTime(){
        return this->departureTime;
    }
    string getArrivalTime(){
        return this->arrivalTime;
    }
    double getCost(){
        return this->cost;
    }
};

int main(){
    Train t("2004", "toyota", 230, 50, "so many");
    Airplane a("2000", "saudia airlines", 800, 600, 1000);
    Bus b("2004", "toyota", 230, 50, "so many");

    BookingSystem<Vehicle> booking1(t, "12-1-2024", "21-1-2024", 3500.05);
    BookingSystem<Vehicle> booking2(a, "234523", "6789", 5.05);
    BookingSystem<Vehicle> booking3(b, "312", "123", 12.0);


    Vehicle vehicle = booking1.getVehicle();
    cout << "Booking 1: " << booking1.getArrivalTime() << endl;
    cout << "Booking 1: " << vehicle.getMake() << " \nmodel: " << vehicle.getModel() << 
    " " << " \nspeed: " << vehicle.getMaxSpeed() << endl;
}
