// Works Correctly and completes all the given task
// but didnt make display info due to waste of time

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Attractions{
    string name;
    int thrillLevel;
    int capacity;
    int duration;

    public:
    Attractions(string name, int thrillLevel, int capacity, int duration) 
    : name(name), thrillLevel(thrillLevel), capacity(capacity), duration(duration) {}
    virtual void displayInfo() = 0;
    virtual void simulateRide() = 0;
};

class RollerCoaster : public Attractions{
    int drops;

    public:
    RollerCoaster(string name, int thrillLevel, int capacity, int duration, int drops) :
    Attractions(name, thrillLevel, capacity, duration), drops(drops){}

    void displayInfo() override {
        cout << "display roller coaster" << endl;
    }
    void simulateRide() override {

    }
};

class WaterRide : public Attractions{
    double waterUsage;

    public:
    WaterRide(string name, int thrillLevel, int capacity, int duration, double waterUsage) :
    Attractions(name, thrillLevel, capacity, duration), waterUsage(waterUsage){}

    void displayInfo() override {
         cout << "display waterride" << endl;
    }
    void simulateRide() override {

    }
};

class Show : public Attractions{
    string performer;

    public:
    Show(string name, int thrillLevel, int capacity, int duration, string performer) :
    Attractions(name, thrillLevel, capacity, duration), performer(performer){}

    void displayInfo() override {
         cout << "display show" << endl;
    }
    void simulateRide() override {

    }
};

class ThemePark{
    Attractions* theme[3];
    int n;

    public:
    ThemePark(){
        // this->theme = Attractions[3];
        this->n = 0;
    }
    void addAttractions(Attractions& obj){
        theme[n] = &obj;
        n++;
    }
    void displayAllAttractions(){
        for(int i = 0; i < this->n; i++){
            theme[i]->displayInfo();
        }
    }
    void simulateDay(){

    }
};
int main(){
    // RollerCoaster* r = new RollerCoaster("rr", 345, 10, 20, 40);
    // WaterRide* w = new WaterRide("wr", 45, 342,67,2.00);
    // Show* s = new Show("show", 54,87,987,"best");
    // Attractions* att[] = {r, w, s};

    Attractions* att[] = {
        new RollerCoaster("rr", 345, 10, 20, 40),
        new WaterRide("wr", 45, 342,67,2.00),
        new Show("show", 54,87,987,"best")
    };

    ThemePark theme;
    theme.addAttractions(*att[0]);
    theme.addAttractions(*att[1]);
    theme.addAttractions(*att[2]);
    theme.displayAllAttractions();
}
