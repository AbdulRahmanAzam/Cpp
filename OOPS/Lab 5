/* Syed Saif ur Rehman Shah (23k-0032) */

#include <iostream>
using namespace std;

class BankAccount{
    private:
    int accountNumber;
    string accountHolderName;
    double balance;
    
    public:
    BankAccount(int accountNumber, string accountHolderName, int balance){
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }
    
    void deposit(double deposit){
        balance += deposit;
        cout << "deposited successfully << endl;
        cout<<"\nCurrent balance: "<<balance;
    }
    
    void withdraw(double withdraw){
        if(withdraw <= balance){
            balance -= withdraw;
            cout << "withdraw successfully" << endl; 
            cout<<"\nCurrent balance: "<<balance;
        }
        else cout<<"\nInsufficient balance";
    }
    
    void display(int i){
            cout<< endl << endl  << "Details of Account "<<i+1<<": ";
            cout<< endl << "Account Number: "<<accountNumber;
            cout<< endl <<"Account Holder Name: "<<accountHolderName;
            cout<< endl << "Account Balance: "<<balance;
    }
};

int main(){
    BankAccount data[3] = {
        BankAccount(34543, "Abdul RAhman Azam", 1000.0),
        BankAccount(1000, "Raghib", 500.0),
        BankAccount(3444, "Talha", 1500.0)
    };
    
    for(int i=0; i<3; i++){
        data[i].display(i);
    }
    int acc; cout<<"\n\nWhich account you want to deposit/withdraw: "; cin>>acc;
    data[acc].deposit(500.0);
    data[acc].withdraw(300.0);
}
