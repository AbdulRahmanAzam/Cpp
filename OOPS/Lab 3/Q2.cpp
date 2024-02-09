#include <iostream>
using namespace std;

class WaterBottle{
    private:
    string company;
    string color;
    int water_capacity;
    
    //getter
    string getcompany(){return this->company;}
    string getcolor(){return this->color;}
    int getwater_capacity(){return this->water_capacity;}
    
    //setter
    void setcompany(string company){this->company = company;}
    void setcolor(string color){this->color = color;}
    void setwater_capacity(int water_capacity){this->water_capacity = water_capacity;}
    
    //methods
    void updatewater_capacity(int water_capacity){
        this->water_capacity = water_capacity;
    }
}

int main(){
    WaterBottle water;
    
    water.setcompany("Aqua");
    water.setcolor("blue");
    water.setwater_capacity(500);
    
    
    cout << "water company " << water.getcompany() << endl << "color " << water.getcolor() << endl << "water capacity " << water.getwater_capacity() << endl;
    
    
    
}
