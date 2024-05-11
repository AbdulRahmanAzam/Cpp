// the check account class is not made because the major learning part is done 


#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class SavingsAccount;

template <typename T>
class Bank{
    public:
    float balance;
    int deposits;
    int withdrawals;
    float annualInterestRate;
    float monthlyServiceCharges;

    Bank(float balance, float annualInterestRate) : balance(balance), annualInterestRate(annualInterestRate) {
        this->deposits = 0;
        this->withdrawals = 0;
        this->monthlyServiceCharges = 850;
    }

    virtual void Deposit(int deposits){
        this->deposits++;
        this->balance += deposits;
    }
    virtual void Withdraw(int withdrawals){
        this->withdrawals++;
        this->balance -= withdrawals;
    }
    virtual void CalcInt(){
        this->balance = balance + ((this->annualInterestRate / 12) * this->balance);
    }
    virtual void MonthlyReport(){
        this->monthlyServiceCharges = 850;
        this->balance -= monthlyServiceCharges;
        this->CalcInt();

        withdrawals = deposits = monthlyServiceCharges = 0;
        
    }
    virtual void Display() = 0;
};

template <typename T>
class SavingsAccount : public Bank<T>{
    bool Status;

    public:
    SavingsAccount(float balance, float annualInterestRate) : Bank<T>(balance, annualInterestRate) {}

    void Withdraw(int withdrawals)override{
        if(Status){
            Bank<T>::Withdraw(withdrawals);
        }else{
            cout << "Account is inactive" << endl;
        }
    }
    void Deposit(int deposits) override{
        if(this->balance + deposits >= 25){
            this->Status = true;
            Bank<T>::Deposit(deposits);
        }else{
            cout << "Deposit must be at least $25" << endl;
        }
    }
    void MonthlyReport()override{
        if(this->withdrawals > 4){
            this->monthlyServiceCharges += 1;
            this->balance--;
            
        }
        Bank<T>::MonthlyReport();
        if(this->balance < 25){
            Status = false;
        }
    }
    void Display(){
         cout << "Balance: " << this->balance 
        << "\ndeposits: " << this->deposits
        << "\nwithdrawals: " << this->withdrawals
        << "\nannualInterestRate: " << this->annualInterestRate
        << "\nmonthlySericeCharge: " << this->monthlyServiceCharges
        << "\nThe account is: " << ((Status) ? "Active" : "Inactive") << endl;
    }
};
int main(){
    SavingsAccount<int> account(200, 10);

    account.Deposit(50);
    account.Withdraw(30);
    account.Display();
    account.MonthlyReport();
    cout << endl;
    account.Display();
}
