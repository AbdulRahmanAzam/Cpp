#include <iostream>
using namespace std;

class Stairs{
    protected:
    int numSteps;
    float stepHeight;
    float stepWidth;
    string location;
    
    public:
    static int countStairs;
    Stairs(int numSteps, float stepHeight, float stepWidth, string location) : numSteps(numSteps), stepHeight(stepHeight), stepWidth(stepWidth), location(location) {};
    
};
int Stairs::countStairs = 0;

class ConveyorBelt{
    float length;
    float width;
    
    protected:
    float speed;
    float capacity;
    
    public:
    static int countConveyorBelt;
    ConveyorBelt(float length, float width, float speed, float capacity) : length(length), width(width), speed(speed), capacity(capacity) {}
    
    ConveyorBelt(float speed, float capacity) : speed(speed), capacity(capacity) {}
    
    void operateBelt(int currWeight){
        
    }
};
int ConveyorBelt::countConveyorBelt = 0;

class Escalator : public Stairs, public ConveyorBelt{
    char direction;
    int currentLocation;
    
    public:
    static int countEscalator;
    Escalator(char direction, int currentLocation, int numSteps, float stepHeight, float stepWidth, string location, float speed, float capacity) : Stairs(numSteps, stepHeight, stepWidth, location), ConveyorBelt(speed, capacity), direction(direction), currentLocation(currentLocation) {};
    
    void moveUp(int weight){
        
    }
    void moveDown(int weight){
        
    }
    
    //getters
    char getdirection(){
        return this->direction;
    }
    int getcurrentLocation(){
        return this->currentLocation;
    }
};
int Escalator::countEscalator =0;

class IndustrialBelt : public ConveyorBelt{
    float minWeight;
    bool operable;
    
    public:
    static int countIndustrialBelt;
    IndustrialBelt(float minWeight, bool operable, float length, float width, float speed, float capacity) : minWeight(minWeight), operable(operable), ConveyorBelt(length, width, speed, capacity) {};
    
    bool checkWeght(int currWeight){
        
    }
    void operateBelt(int currWeight){
        
    }
    void operateBelt(int currWeight, int speed) {}
};
int IndustrialBelt::countIndustrialBelt = 0;

int main() {


    cout << "The total count  are " << endl
    << "Stairs  " << countStairs << endl
    << "ConveyorBelt  " << countConveyorBelt << endl
    << "Escalator  " << countEscalator << endl
    << "INdustrialBelt  " << countIndustrialBelt << endl;
}




















