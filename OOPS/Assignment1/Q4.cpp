#include <iostream>
using namespace std;

class Roller_Coaster {
    private:
    string name;
    int height;
    int length;
    int speed;
    int capacity;
    int currentNumRiders;
    bool rideInProgress;

    public:
    //constructors
    Roller_Coaster(string name = "roller coaster", int height = 500, int length = 2000, int capacity = 20, bool rideInProgess = false){
        this->name = name;
        this->height = height;
        this->length = length;

        if(capacity % 2 || capacity % 3)
            capacity--;

        this->capacity = capacity;
        this->rideInProgress = rideInProgess;
    }
    // setter
    void setname(string name){
        cout << "The name of the Roller coaster is set to " << name << endl;
        this-> name = name;
    }
    void setheight(int height){
        cout << "The height of the Roller coaster is set to " <<  height << endl;
        this -> height = height;
    }
    void setlength(int length){
        cout << "The length of the ROller coaster is set to "<< length << endl;
        this->length = length;
    }
    void setspeed(int speed){
        cout << "The speed of the Roller Coaster is set to " << speed << endl;
        this->speed = speed;
    }
    
    // getter



    //functions
    // load the rider
    int load(int currentNumRiders){
        while(capacity && currentNumRiders){
            capacity--;
            currentNumRiders--;
        }
        return currentNumRiders;
    }

    int startTheRide(){
        // ride is in progress
        if(rideInProgress){
            cout << "Ride is in prpgress " << endl;
            return -1;
        }else{ // ride is not in progress
        
            // if capacity is more than 0
            if(capacity > 0){
                cout << "There are more seats on the ROller coaster" << endl;
                return capacity;
            // if seats are full
            }else{
                cout << "Ride is started" << endl;
                rideInProgress = true;
            }
        }
    }

    void StopTheRide(){
        if(rideInProgress){

            cout << "Ride is stopped" << endl;
            rideInProgress = false;
            return;
        }
        cout << "Ride is already stopped" << endl;
    }

    void unload(){
        if(!rideInProgress){
            capacity = 0;
            cout << "Capacity unloaded" << endl;
        }
    }

    void accelerate(){ // since my roll no is 0061 so increment 1
        cout << "Accelerate by 1" << endl;
        speed += 1;
    }
    void brake(){ // roll no 0061 so decrement 6
        cout << "Brake are decellerating at 6 " << endl;
        speed -= 6;
    }

};

int main(){
    Roller_Coaster R1("roller coaster", 500, 2000, 20, false);
    Roller_Coaster R2;

    R2.setname("Dragon Ball Z");
    R2.setlength(200);
    R2.setheight(100);
    R2.setspeed(60);

    R2.load(20);
    R2.startTheRide();
    R2.accelerate();
    R2.accelerate();
    R2.accelerate();
    R2.brake();
    R2.StopTheRide();
    R2.unload();


    return 0;
}
