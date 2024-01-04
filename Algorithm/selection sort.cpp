#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{   
    for(int i =0; i< n; i++){
        int minIndex = i;

        for(int j= i+1; j<n ;j++){
            //finding minimum from the index after i
            if(arr[j] < arr[minIndex])
                minIndex = j;
                
        }
        // swapping the minimum
        swap(arr[minIndex], arr[i]);
    }
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = 5;
    
    selectionSort(arr, n);
    for(int i=0; i< n ;i++){
        cout << arr[i] << " ";
    }
}
