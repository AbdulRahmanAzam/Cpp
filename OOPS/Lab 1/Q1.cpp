#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cout << "Enter a positive number" <<endl;
    cin >> n;
    bool temp = true;
    
    for(int i = n-1; i > 1 ; i--){
        if(n % i == 0){
            temp = false;
        }
    }
    
    if(!temp){
        cout << "the number is not prime";
    }else{
        cout << "the number is prime";
    }
    return 0;
}
