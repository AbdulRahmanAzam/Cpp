#include <iostream>
#include <vector>
using namespace std;

int factorial(vector<int>& arr, int n){
    if(n == 0){
        arr[0] = 1;
        return 1;
    }
        arr[n-1] = n * factorial(arr, n -1);
        return arr[n-1];
}
int main() {
    int n = 5;
    vector<int> arr (n+1, 0);
    
    cout << factorial(arr, n) << endl << endl;
    
    for(int i=0; i< n ; i++){
        cout << arr[i] << endl;
    }
}
