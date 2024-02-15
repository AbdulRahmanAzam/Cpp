#include <iostream>
#include <array>
using namespace std;

class Office {
    private:
    string location = "";
    int SeatingCapacity = 0;
    array<string, 3> Furniture = {"", "", ""};

    public:
    //parametrized constructor
    Office(string location = "", int SeatingCapacity = 0, array<string, 3> Furniture = {"","",""}) : location(location), SeatingCapacity(SeatingCapacity), Furniture(Furniture){}
};

int main(){
    Office office1("KHI", 2000, {"chair","table","bed"});

    Office office2("HYD",1000);
    Office office3("LHR");
}
