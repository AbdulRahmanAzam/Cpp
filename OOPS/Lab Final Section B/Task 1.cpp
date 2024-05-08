#include <iostream>
using namespace std;

class Tour{
    string name;
    int duration;
    string destination;

    public:
    Tour(string name, int duration, string destination) : name(name), duration(duration), destination(destination) {}
    virtual ~Tour(){}

    virtual void calculateTicketPrice() = 0;

    virtual void scheduleTour() = 0;
    
};

class AdventureTour : public Tour{
    public:

    AdventureTour(string name, int duration, string destination) : Tour(name, duration, destination){}

    void calculateTicketPrice() override {
        cout << " Pricing may be based on activites and tour duration" << endl;
    }

    void scheduleTour() override {
        
    }
};

class CulturalTour : public Tour{
    public:

    CulturalTour(string name, int duration, string destination) : Tour(name, duration, destination){}

    void calculateTicketPrice() override {
        cout << "Pricing may be based on number of sites visited and additional experience" << endl;
    }

    void scheduleTour() override {

    }
};

class WildlifeTour : public Tour{
    public:

    WildlifeTour(string name, int duration, string destination) : Tour(name, duration, destination){}

    void calculateTicketPrice() override {
        cout << "Pricing may be based on the rarity of sightings and guide expertise" << endl;
    }

    void scheduleTour() override {

    }
};

int main(){
    cout << "Hello World" << endl;
    AdventureTour at("anas", 300, "azeezabad");
    CulturalTour ct("talha", 400, "shehzadpur");
    WildlifeTour wt("fahad", 50, "tando adam");


    Tour* t[] = {&at, &ct, &wt};
    
    for(int i = 0; i < 3; i++){
        t[i]->calculateTicketPrice();
        t[i]->scheduleTour();
    }
}
