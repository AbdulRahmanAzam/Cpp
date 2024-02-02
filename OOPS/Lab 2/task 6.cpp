#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    return(b,a % b);
}

int LCM(int a, int b){
    static int high = max(a,b), low = min(a,b), res = high;
    if(res % low == 0) return res;
    res += high;
    return LCM(a,b);
}

int main(){
    int a = 6, b = 4;
    cout << GCD(a,b) << endl; 
    cout << LCM(a,b) << endl;
}



