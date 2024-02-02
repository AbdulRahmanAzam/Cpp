int maxwater(int *arr, int n){
    int maxarea = 0;
    for(int i =0; i< n; i++){
        for(int j=0; j< n; j++){
            if(i != j)
                maxarea = max(maxarea, abs(i-j) * min(arr[i], arr[j]));
        }
    }
    return maxarea;
}
int main(){
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    
    cout << "Maximum amount of water is " << maxwater(arr,n);
}
