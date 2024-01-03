#include <iostream>
using namespace std;
void printArray(int *arr, int n){
    for(int i=0; i< n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[6] = {0,1,0,1,0,1};
    int n=6;
    int i=0, j=n-1;
            
    while(i  < j){
        while(arr[i] == 0){
            i++;
        }
        while(arr[j] == 1){
            j--;
        }   
        if(i < j) {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }    
    printArray(arr,n);
}






