// Abdul Rahman Azam
// 23k-0061
// date: 9/feb/2024

#include <iostream>
using namespace std;

class WaterBottle{
    private:
    string company;
    string color;
    int water_capacityl;
    int water_capacityml;
    
    public:
    //getter
    string getcompany(){return this->company;}
    string getcolor(){return this->color;}
    int getwater_capacityl(){return this->water_capacityl;}
    int getwater_capacityml(){return this->water_capacityml;}
    
    //setter
    void setcompany(string company){this->company = company;}
    void setcolor(string color){this->color = color;}
    void setwater_capacity(int water_capacityml){
        this->water_capacityml = water_capacityml;
        this->water_capacityl = water_capacityml / 1000;
    }
    
    //methods
    void updatewater_capacity(int water_capacityml){
        this->water_capacityml = water_capacityml;
        this->water_capacityl = water_capacityml / 1000;
    }
};

int main(){
    WaterBottle bottle;
    
    bottle.setcompany("Aqua");
    bottle.setcolor("blue");
    bottle.setwater_capacity(500);
    
    
    cout << "water company " << bottle.getcompany() << endl << "color " << bottle.getcolor() << endl << "water capacity in litre " << bottle.getwater_capacityl() << endl << "water capacity in millilitres" << bottle.getwater_capacityml() << endl;
    
    bottle.updatewater_capacity(1000);
    
    cout << endl << "water capacity is updated to in littre " << bottle.getwater_capacityl() << endl << " in millilitre " << bottle.getwater_capacityml() << endl;
}
