#include <iostream>
using namespace std;

bool isSorted(int *arr, int size){
  //base case
    if(size == 0 or size == 1){
        return true;
    }
    //checking for greater 
    if(arr[0] > arr[1]){
        return false;
    }else{ // since arr is pointer so increase by one, and size decrease by 1
        return isSorted(arr + 1, size - 1);
    }
}
int main(){
    int arr[] = {1,2,3,4,6,5};
    int size = 6;
    int ans = isSorted(arr,size);
    
    if(ans){
        cout << "array is sorted";
    }else{
        cout << "array is not sorted";
    }
}
