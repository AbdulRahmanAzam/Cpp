#include <iostream>
using namespace std;

// int power(int a, int b){
//     if(b == 0) return 1;
//     return a * power(a,b-1);
// }

// more optimised
int power(int a, int b){
    if(b==0) return 1;
    
    if(b==1) return a;
    
    int ans = power(a, b/2);
    
    //if b is odd
    if(b%2){
        return a * ans * ans;
        
    }else{ 
        // if b is even
        return ans * ans;
    }
}

int main(){
    int a = 3;
    int b = 4;
    cout << power(a,b) << endl;
}
