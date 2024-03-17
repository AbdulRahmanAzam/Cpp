#include <iostream>
#include <string>
#include <vector>
using namespace std;

class appointment{
    private:
    string name;
    int earn;
    static int total_appointment;
    static int total_earning;

    public:
    appointment(string name,int earn){
        this->name = name;
        this->earn = earn;
        total_appointment++ ;
        total_earning  += earn;
    }
    
    string getname(){
        return this->name;
    }
    int getearn(){
        return this->earn;
    }

    static int avgcost(){
        return total_earning / total_appointment;
    }
    
    static int gettotal_earning(){
        return total_earning;
    }
    
    static int gettotal_appointment(){
        return total_appointment;
    }
};

int appointment::total_appointment = 0;
int appointment::total_earning = 0;
 
int main(){
    
    appointment a("Abdul Rahman Azam", 6000), b("Abdul Basit", 1000), c("Paaji", 4000);
    
    cout << "Average Cost = " << appointment::avgcost() << endl
    << "Total earning = " << appointment::gettotal_earning() << endl
    << "Total Appointment = " << appointment::gettotal_appointment() << endl;
}
