
#include <iostream>
using namespace std;

class DarazPersonData{
    private:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phone;
    
    public:
    // setters or mutators
    void setfirstName(string firstName){
        this->firstName = firstName;
    }
    void setlastName(string lastName){
        this->lastName = lastName;
    }
    void setaddress(string address){
        this->address = address;
    }
    void setcity(string city){
        this->city = city;
    }
    void setstate(string state){
        this->state = state;
    }
    void setzip(string zip){
        this->zip = zip;
    }
    void setphone(string phone){
        this->phone = phone;
    }


    //getters or accessors
    string getfirstName(){
        return this->firstName;
    }
    string getlastName(){
        return this->lastName;
    }
    string getaddress(){
        return this->address;
    }
    string getcity(){
        return this->city;
    }
    string getstate(){
        return this->state;
    }
    string getzip(){
        return this->zip;
    }
    string getphone(){
        return this->phone;
    }

};

class DarazCustomerData : public DarazPersonData {
    private:
    int customerNumber;
    int loyaltyPoints;

    public:
    //setters
    void setcustomerNumber(int customerNumber){
        if(customerNumber > 0)
            this->customerNumber = customerNumber;
        else
            cout << "Customer Number should not be negative" << endl;
    }
    void setloyaltyPoints(int loyaltyPoints){
        if(loyaltyPoints <0){
            cout << "Loyalty Points cannot be set becuase it is negative" << endl;
            return;
        }
        this->loyaltyPoints = loyaltyPoints;
    }

    //getters
    int getcustomerNumber(){
        return customerNumber;
    }
    int getloyaltyPoints(){
        return this->loyaltyPoints;
    }
};


class DarazLoyaltyProgram : public DarazCustomerData{
    public:
    
    void addloyaltyPoints(int addPoints){
        if(addPoints <0){
            cout << "Loyalty Points cannot be added becuase it is negative" << endl;
            return;
        }
        cout << "Adding loyalty points for purchases = " << addPoints << endl;

        int n = getloyaltyPoints();
        n += addPoints;
        setloyaltyPoints(n);
    }

    void redeemloyaltyPoints(int subtractPoints){
        if(subtractPoints < 0){
            cout << "We cannot subtract loyalty points in negative" << endl;
            return;
        }

        cout << "Redeeming loyalty Points for discounts = " << subtractPoints << endl;
        setloyaltyPoints(getloyaltyPoints() - subtractPoints);
    }

    void displayloyaltyPoints(){
        cout << "You have a total LoyaltyPoints of = " << getloyaltyPoints() << endl << endl;
    }
};

int main(){
    DarazLoyaltyProgram user1;
    user1.setfirstName("Abdul Rahman");
    user1.setlastName("Azam");
    user1.setcity("Karachi");
    user1.setaddress("Gulshan e Iqbal");
    user1.setphone("03163677527");
    user1.setstate("Sindh");
    user1.setzip("75300");
    
    user1.setcustomerNumber(55);
    user1.setloyaltyPoints(5);
    user1.displayloyaltyPoints();

    user1.addloyaltyPoints(60);
    user1.displayloyaltyPoints();

    user1.redeemloyaltyPoints(45);
    user1.displayloyaltyPoints();
}
