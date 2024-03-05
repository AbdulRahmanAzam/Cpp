// Abdul Rahman Azam 23k-0061
// 5/ 3/ 2024

#include <iostream>
using namespace std;

class loanHelper{
    private:
    const float rate = 0.5;
    int amount;
    int amount_months;
    
    public:
    loanHelper(int amount, int amount_months){
        int loan = (amount / amount_months) / rate ;
        display(amount_months,loan);
    }
    
    void display(int amount_months,int loan){
        cout << "You have to pay " << loan << " everymonth for " << amount_months << " months to repay your loan" << endl; 
    }
};

int main(){
    loanHelper(12000, 12);
}
