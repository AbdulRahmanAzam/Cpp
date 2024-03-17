#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class BankAccount{
    private:
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;
    
    public:
    BankAccount(int accountId, double balance, int numTransactions) : accountId(accountId), balance(balance), numTransactions(numTransactions) {
        transactionHistory = new int
    }
    
    BankAccount(const BankAccount& other) : accountId(accountId), balance(balance), numTransactions(numTransactions){
        
    }
    
    ~BankAccount(){
        delete[] transactionHistory;
        cout << "memory freed successfully" << endl;
    }
    
    void display(){
        cout << "Account id = " << this->accountId << endl
        << "balance = " << this->balance << endl;
        << "Transaction history :" << endl;
        
        for(int i=0; i< numTransactions; i++){
            cout << transactionHistory[i] << " ";
        }
    }
    
    void updateTransactionHistory(){
        
    }
        
};

int main(){
    
}
