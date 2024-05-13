#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Property{
    public:
    string address;
    double reservePrice;

    Property(string address, double reservePrice) : address(address), reservePrice(reservePrice) {}

    friend void displayWinningBidder(){};
    friend void displayBiddingSystemInfo(){};
};

class Bid{
    public:

    virtual void placeBid() = 0;
    virtual void displayBidInfo() = 0;
    
};

class Bidder : public Bid{
    public:
    string name;
    double bidAmount;

    Bidder(string name, double bidAmount) : name(name), bidAmount(bidAmount) {}

    void placeBid(){
        cout << "Enter your bid amount: ";
        cin >> this->bidAmount;
    }
    void displayBidInfo(){
        cout << "Bidder Name: " << this->name << endl;
        cout << "bid Amount: " << this->bidAmount << endl;
    }
};

class PropertyBiddingSystem{
    Bidder* bidders[3];
    int numBidders;
    
    public:
    PropertyBiddingSystem(){
        numBidders = 0; 
    }
    void addBidder(Bidder& obj){
        if(numBidders >= 3)
            return;

        bidders[numBidders] = &obj;
        numBidders++;
    }

    void displayWinningBidder(Property& property){
        for(int i=0;i < numBidders ; i++){
            if(bidders[i]->bidAmount >= property.reservePrice){
                cout << "The winning bidder is " << bidders[i]->name << endl;
                cout << "with the Bid Amount of " << bidders[i]->bidAmount << endl << endl;
            }
        }
    }
 
    void displayBiddingSystemInfo(Property& property){
        for(int i=0;i < numBidders ; i++){
            cout << "Bidder " << i+1 << " Name: " << bidders[i]->name << endl
            << "Bid Amount: " << bidders[i]->bidAmount << endl
            << "Address: " << property.address << endl
            << "Reserve Price: " << property.reservePrice << endl << endl;
        }
    }
};
int main(){
    Property p1("123 Main St", 3);
    Bidder b1("A", 1);
    Bidder b2("B", 2);
    Bidder b3("C", 3);
    Bidder b4("D", 4);

    PropertyBiddingSystem p;

    p.addBidder(b1);
    p.addBidder(b2);
    p.addBidder(b3);
    p.addBidder(b4);

    p.displayBiddingSystemInfo(p1);

    p.displayWinningBidder(p1);
}
