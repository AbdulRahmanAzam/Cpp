#include <iostream>
using namespace std;

// void bubbleSort(int *arr, int i, int j, int n){
//   // when j reaches end
//     if(j == n+1){
//         i++;
//         j = i+1;
//     }

//     //when i reaches end
//     if(i == n)
//         return;
//     // swap when needed
//     if(arr[i] > arr[j])
//         swap(arr[i], arr[j]);

//   //recursive reference
//     return bubbleSort(arr, i, j + 1, n);
// }

void sortArray(int *arr, int n){
    if (n <= 1) return;
    
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    
    sortArray(arr, n-1);
}


int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;
    
    // bubbleSort(arr, 0, 1, n - 1);
    sortArray(arr,n);
    
    for(int x:arr){
        cout << x << " ";
    }
}
