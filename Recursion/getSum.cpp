#include <iostream>
using namespace std;

int getSum(int *arr, int size){
    if(size < 0) return 0;
    return arr[size] + getSum(arr, size - 1);
}
int main(){
    int arr[] = {1,2,3,4};
    int size= 4;
    int sum = 0;
    cout << getSum(arr,size-1) << endl;
}
