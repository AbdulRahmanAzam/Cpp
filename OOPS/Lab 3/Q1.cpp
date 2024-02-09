#include <iostream>
using namespace std;

class BoardMarker {
    private: 
    string Brand;
    string Shade;
    bool Refilliable;
    bool Ink_Status;
    
    //setter
    void setbrand(string Brand){this->Brand = Brand;}
    void setshade(string Shade){this->Shade = Shade;}
    void setRefilliable(bool Refilliable){this->Refilliable = Refilliable;}
    void setInk_Status(bool Ink_Status){this->Ink_Status = Ink_Status;}
    
    //getter
    string getBrand(){return Brand;}
    string getShade(){return Shade;}
    bool getRefilliable(){return Refilliable;}
    bool getInk_Status(){return Ink_Status;}
    
    //methods
    
}
int main() {
    BoardMarker marker;
    
}
