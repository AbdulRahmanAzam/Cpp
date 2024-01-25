#include <iostream>
#include <vector>
using namespace std;

int fibo(vector<int>& arr, int n){
    if(n < 2){
        arr[n-1] = n;
        return n;
    }
    
    arr[n-1] = fibo(arr, n-2) + fibo(arr, n-1);
    return arr[n-1];
}

int main() {
    int n = 8;
    vector<int> arr (n, 0);
    
    cout << fibo(arr, n) << endl << endl;
    
    for(int i=0; i< n ; i++){
        cout << arr[i] << endl;
    }
}
