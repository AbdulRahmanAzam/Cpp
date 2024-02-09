// Abdul Rahman Azam
// 23k-0061
// date: 9/feb/2024

#include <iostream>
using namespace std;

class BoardMarker {
    private: 
    string Brand;
    string Shade;
    bool Refilliable;
    bool Ink_Status;
    
    public:
    //setter
    void setBrand(string Brand){this->Brand = Brand;}
    void setShade(string Shade){this->Shade = Shade;}
    void setRefilliable(bool Refilliable){this->Refilliable = Refilliable;}
    void setInk_Status(bool Ink_Status){this->Ink_Status = Ink_Status;}
    
    //getter
    string getBrand(){return Brand;}
    string getShade(){return Shade;}
    bool getRefilliable(){return Refilliable;}
    bool getInk_Status(){return Ink_Status;}
    
    //methods
    void writing(bool Ink_Status){
        if(Ink_Status)
            cout << "The is available " << endl;
        else
            cout << "The ink is running out" << endl;
    }
    
    void refill(bool Refilliable){
        if(Refilliable)
            cout << "The marker is refilliable" << endl;
        else
            cout << "The marker is not refilliable " << endl;
    }
};

int main() {
    BoardMarker marker;
    
    marker.setBrand("Dollar");
    marker.setShade("black");
    marker.setRefilliable(true);
    marker.setInk_Status(false);
    
    cout << "Brand is = " << marker.getBrand() << endl;
    cout << "Shade is = " << marker.getShade() << endl;

    marker.refill(marker.getRefilliable());
    marker.writing(marker.getInk_Status());      
}
