#include <iostream>
using namespace std;
void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    //length for 2 sub arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;
    //initialiuze 2 sub array
    int *first = new int[len1];
    int *second = new int[len2];
    
    //copying values of main arr to them
    int index = s;
    for(int i=0; i < len1; i++){
        first[i] = arr[index++];    
    }
    
    index = mid + 1;
    for(int i=0; i< len2; i++){
        second[i] = arr[index++];
    }
    
    //sorting and filing
    int index1 = 0;
    int index2 = 0;
    index = s;
    
    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[index++] = first[index1++];
        }else{
            arr[index++] = second[index2++];
        }
    }
    while(index1 < len1){
        arr[index++] = first[index1++];
    }
    while(index2 < len2){
        arr[index++] = second[index2++];
    }
}

void  mergeSort(int *arr, int s, int e){
    //base case
    if(s == e) return;

    int mid = (s+e)/2;
    // sort left part
    mergeSort(arr,s,mid);
    //sort right part
    mergeSort(arr,mid+1,e);
    //merging them
    merge(arr, s, e);
}

int main(){
    int arr[10] = {5,3,2,4,1,7,8,6,9,0};
    int n = 10;
    
    mergeSort(arr,0,n-1);
    
    for(int i=0; i < n; i++){
        cout << arr[i] << ' ' ;
    }
}
