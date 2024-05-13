#include <iostream>
#include <string>
using namespace std;

class Sport{
    public:
    string current_champ;
    int start_year;
    string headquarter_location;

    Sport(string current_year, int start_year, string headquarter_location) : 
    current_champ(current_year), start_year(start_year), headquarter_location(headquarter_location) {}

    Sport(){}
};

class Tournament{
    Sport* sport;

    public:
    Tournament(){
        sport = new Sport();
    }
    Tournament(string current_year, int start_year, string headquarter_location) {
        this->sport = new Sport(current_year, start_year, headquarter_location);
    }

    virtual void Begin_Tournament(Sport& sport){
        if(sport.headquarter_location == "Karachi" || sport.headquarter_location == "Toronto")
            cout << "Tournament Begins" << endl;
    }
};

class WorldCup : public Tournament{
    public:

    void Begin_Tournament(Sport& sport) override{
        if(sport.start_year > 1950 && !(sport.headquarter_location == "Karachi" || sport.headquarter_location == "Toronto"))
            cout << "World Cup begins" << endl;
    }
};

template <typename T>
void PrintIt(T val){
    cout << val << endl;
}

int main(){
    WorldCup W;

    Sport sports("done", 1950, "Karachi");
    W.Begin_Tournament(sports);
}
