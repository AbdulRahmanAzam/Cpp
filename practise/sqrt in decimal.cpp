#include <iostream>
using namespace std;

long long int sqrtInt(int n){
    long long int s = 0, e = n, ans = -1;
    while(s <= e){
        long long int mid = s + ( e -s )/2;
        if(mid * mid == n){
            return mid;
        }
        if(mid*mid < n){
            ans = mid;
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    return ans;
}

double moreprecision(int n, int precise, double val){
    double factor = 1;
    
    for(int i = 0; i < precise; i++){
        factor = factor / 10;
        
        for(double j = val; j*j < n;j = j + factor){
            val = j;
        }
    }
    return val;
}
int main(){
    int n = 38;
    int mainval = sqrtInt(n);
    cout << "more precise " << moreprecision(n,5,mainval) << endl;
}
