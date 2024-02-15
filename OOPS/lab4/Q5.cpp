#include <iostream>
#include <array>
#include <string>
// #include <pointer>
using namespace std;

class Office {
    private:
    string location = "";
    int SeatingCapacity = 0;
    string* Furniture;

    public:
    //constructor
    Office(string location = "", int SeatingCapacity = 0, int size = 3){
        this->location = location;
        this->SeatingCapacity = SeatingCapacity;
        Furniture = new string[size];
    }

    //destructor
    ~Office(){
        cout << "Destrucutor called successfully " << endl;
        delete[] Furniture;
    }
};

int main(){
    Office office1("KHI", 2000, 5);
    Office office2("HYD",1000);
    Office office3("LHR");
}
