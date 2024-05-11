
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void printArrayRange(const vector<T>& arr, int start, int end){
    if(start >= end || start < 0 || end > arr.size()){
        cout << "range error" << endl;
        return;
    }
    for(int i = start; i < end ; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    vector<int> arri = {1,2,3,4,5,6,7,8,9};
    vector<float> arrf = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    vector<char> arrc = {'A','B','C','D','E','F','G'};
    
    printArrayRange(arri, 0, 3);
    cout << endl;
    printArrayRange(arrf, 0, 7);

    cout << endl;
    printArrayRange(arrc, 3, 7);
    
}
