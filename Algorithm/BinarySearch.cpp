#include <iostream>
using namespace std;
void printArray(int *arr, int n){
    for(int i=0; i< n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int binarySearch(int arr[], int k){
    // finding first value of the array and the last value
    int start = 0;
    int end = sizeof(arr)/ arr[0] - 2; // this was some type of error
    
    int mid = start + (end - start)/2;
    
    while(start <= end){
        if(arr[mid] == k){
            return mid;
            
        }else if(k > arr[mid]){// k is in second part then go for second
            start = mid +1;
            
        }else if(k < arr[mid]){// k is in first part then go for first
            end = mid -1;
        }
        // mid is changes due to change in part
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int arr[] = {1 ,4 ,5 ,6,6,7,7 };
    int find = 5;
    int index = binarySearch(arr,find);
    cout << "index of " << find << " is " << index << endl;
    printArray(arr,n);
}






