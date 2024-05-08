#include<iostream>
#include <vector>
using namespace std;

class Seat{
    int row;
    int seatNumber;
    bool reserved;

    public:
    Seat(){}
    virtual ~Seat(){}

    void reserve(){
        reserved = true;
    }
    void cancelReservation(){
        reserved = false;
    }
    bool getStatus(){
        return reserved;
    }

};

class Theater{
    vector<vector<Seat>> seats;

    bool isValidSeat(int row, int seat){
        if(row < 0 || row >= seats.size())
        {
            return false;
        }
        if(seat < 0 || seat >= seats[row].size())
        {
            return false;
        }
        return true;
    }

    public:
    Theater(int rows, int seatsPerRow){
        initializeSeats(rows, seatsPerRow);
    }
    virtual ~Theater(){}

    void initializeSeats(int rows, int seatsPerRow){
        seats.resize(rows);
        for(int i=0; i < rows; i++){
            seats[i].resize(seatsPerRow);
        }
    }
    void viewAvailableSeats(){
        for(int i=0; i < seats.size(); i++){
            for(int j = 0;j < seats[i].size(); j++){
                if(seats[i][j].getStatus()){
                    cout << "Seat number: " << i << " Row and " << j << "Seatno per row" << "  R" << endl ;
                }else{
                    cout << "Seat number: " << i << " Row and " << j << "Seatno per row" << "  not Reserved" << endl ;
                }
            }
        }
    }

    void reserve(int row, int seat){
        if(isValidSeat(row, seat)){
            seats[row][seat].reserve();
        }
    }
    void cancelReservation(int row, int seat){
        if(isValidSeat(row, seat)){
            seats[row][seat].cancelReservation();
        }
    }
};

int main(){
    Theater t(6, 6);
    t.viewAvailableSeats();
    t.reserve(5,5);
    t.reserve(2,4);
    t.reserve(20,10);
    t.cancelReservation(5,5);
    t.viewAvailableSeats();

}
