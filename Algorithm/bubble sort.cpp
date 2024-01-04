#include <iostream>
using namespace std;

int main(){
    int arr[] = {5,4,3,2,1};
    int n = 5;
    
    for(int i =0; i< n; i++){
        bool swapped = false;
        for(int j = 0; j< n - i - 1; j++){
            
            if(arr[j] > arr[j+1]){
                swap(arr[j+1], arr[j]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
    for(int i=0; i< n ;i++){
        cout << arr[i] << " ";
    }
}
