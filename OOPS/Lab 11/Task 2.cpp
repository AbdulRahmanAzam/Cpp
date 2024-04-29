#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Account{
    protected:
    int accountNumber;
    double balance;

    public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}
    virtual ~Account() = default;

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() = 0;

    int getAccountNumber(){
        return this->accountNumber;
    }
    double getBalance(){
        return this->balance;
    }
};

class SavingsAccount : public Account{
    double interestRate;

    public:
    SavingsAccount(double interestRate, int accountNumber, double balance) :
    Account(accountNumber, balance), interestRate(interestRate) {}
    ~SavingsAccount(){};

    void deposit(double amount) override {
        this->balance -= amount;
    }
    void withdraw(double amount) override {
        this->balance += amount;
    }
    void calculateInterest() override {
        cout << "The Interest for the Savings account of 1 year is: " << this->balance * 12 * this->interestRate << endl;
    }
};

class CurrentAccount : public Account{
    double overdraftLimit;

    public:
    CurrentAccount(double overdraftLimit, int accountNumber, double balance) :
    Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}
    ~CurrentAccount(){}

    void deposit(double amount) override {
        this->balance -= amount;
    }
    void withdraw(double amount) override {
        this->balance += amount;
    }
    void calculateInterest() override {
        cout << "There is no interest for the current Account: " << this->balance * 12 * 0 << endl;
    }
};

int main(){
    SavingsAccount s(12, 523, 2000);
    CurrentAccount c(10000, 234, 20000);

    s.deposit(250);
    s.withdraw(500);
    cout << "The account number is : " << s.getAccountNumber() << endl;
    cout << "The account balance is: " << s.getBalance() << endl;
    s.calculateInterest();

}
