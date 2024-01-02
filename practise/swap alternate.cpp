//convert this {1,2,3,4,5,6};   
//convert to  {2,1,4,3,6,5}
//index EVEN to index ODD and vice versa
#include <iostream>
using namespace std;
int main(){
    int arr[6] = {1,2,3,4,5,6};
    //convert to {2,1,4,3,6,5}
    int n = 6;
    for(int i=0; i< n; i++){
        if((i&1) == 0){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    
    for(int i=0; i< n ; i++)  cout << arr[i] << " ";
    
}
