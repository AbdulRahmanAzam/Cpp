//extra cout are given to get the logic behind it or the main idea
#include <iostream>
using namespace std;

int main(){
    int arr[] = {5,4,3,2,1};
    int n = 5,i , j;
    
    // outer loop till all the inputs
    for(i=1; i< n; i++){
        int temp = arr[i];
        
        // from particular position to start of the array
        for(j = i - 1; j >= 0 ; j--){
            // empyting the place for 
            if(arr[j] > temp){
                arr[j+1] = arr[j];
                cout << arr[j] << " " << arr[i] << " " << temp << endl;
            }
        }
        // cout << endl;
        arr[j+1] = temp;
        
        for(int i=0; i< n ;i++){
            cout << arr[i] << " ";                           
        }
            cout << endl << endl;
    }
    
    
}
