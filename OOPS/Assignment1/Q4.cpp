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
        this-> name = name;
    }
    void setheight(int height){
        this -> height = height;
    }
    void setlength(int length){
        this->length = length;
    }
    void setspeed(int speed){
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
            return -1;
        }else{ // ride is not in progress
        
            // if capacity is more than 0
            if(capacity > 0){
                return capacity;
            // if seats are full
            }else{
                rideInProgress = true;
            }
        }
    }

    void StopTheRide(){
        if(rideInProgress){
            rideInProgress = false;
        }
    }

// bhand
    void unload(){
        if(!rideInProgress){
            capacity;
        }
    }

    void accelerate(){
        speed += 1;
    }
    void brake(){
        speed -= 6;
    }

};

int main(){
    // Roller_Coaster("roller coaster", 500, 2000, 20, false);
    Roller_Coaster();

    return 0;
}
