#include <iostream>
using namespace std;
void printArray(int *arr, int n){
    for(int i=0; i< n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sort01(int arr[],int n){
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
}
void sort012(){
    int low =0 , mid = 0, high = n - 1;
    
    //if mid is 2 then decrement high
    //if mid is 1 then increment mid
    //if mid is 0 then swap with low, mid++, low++
    
    while(mid <= high){
        if(arr[mid] == 0){
             swap(arr[mid], arr[low]);
             mid++;
             low++;

        }else if(arr[mid] == 1){
            mid++;

        }else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    int arr[6] = {0,1,0,1,0,1};
    int n=6;
    sort01(arr, n);
    sort012(arr,n);
    printArray(arr,n);
}






