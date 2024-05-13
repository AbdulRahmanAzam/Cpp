// I completed correctly but just the "main" part and the "display" part is little bit confusing
// if you find it correct just let me know, through any of the social media accounts

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Hotel{
    string name;
    string location;
    int starRating;

    public:
    string getName(){
        return this->name;
    }
    string getLocation(){
        return this->location;
    }
    int getStarRating(){
        return this->starRating;
    }
};

class Luxuryhotel : public Hotel{
    int numberOfRooms;
    string amenities;
    bool cuisine;

    public:
    int getNumberOfRooms(){
        return this->numberOfRooms;
    }
    string getAmenities(){
        return this->amenities;
    }

};

class Budgehotel : public Hotel{
    int numberOfRooms;
    string amenities;

    public:
    int getNumberOfRooms(){
        return this->numberOfRooms;
    }
    string getAmenities(){
        return this->amenities;
    }
};

class Resort : public Hotel{
    int numberOfRooms;
    string activities;

    public:
    int getNumberOfRooms(){
        return this->numberOfRooms;
    }
    string getActivites(){
        return this->activities;
    }

};

template <typename T>
class BookingSystem{
    T* hotel;

    public:
    BookingSystem(T* hotel) : hotel(hotel) {}

    void display(Hotel& hotel){
        cout << "name: " << hotel.getName() << endl;
    }
};

int main(){
    Resort r;
    BookingSystem<Hotel> booking(new Resort());

    booking.display(r);
}
