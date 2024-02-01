#include <iostream>
using namespace std;


bool hasSubsetSum(int arr[], int size, int targetSum){
    int sum = arr[]
    if(targetSum ==  sum){
        return true;
    }
    
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int targetSum = 12, y;

    int y = hasSubsetSum(arr, n, );

    // for(int i = 0; i< n; i++){
    //     int sum = 0;
    //     for(int j = i; j < n; j++){
    //         sum += arr[j];
    //     }
    //     if(sum == targetSum){
    //         y = true;
    //         break;
    //     }
    // }
    if(y){
        cout << "Sub set is available" << endl;
    }else{
        cout << "Subset is not available" << endl;
    }
}
