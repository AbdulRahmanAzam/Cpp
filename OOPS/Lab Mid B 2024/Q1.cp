#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

class StatisticalAnalyzer{
    public:
    int calculateStandardDeviation(int arr[], int n){
        int mean = 0;
        for(int i=0; i< n; i++){
            mean += arr[i];
        }
        mean /= n;
        
        int numerator = 0;
        for(int i =0; i<n ; i++){
            numerator += (arr[i] - mean) * (arr[i] - mean);
        }
        
        return sqrt(numerator / (n-1));
    }
    
    static double computeAverage(int arr[], int n){
        double sum=0;
        for(int i=0; i< n; i++){
            sum += arr[i];
        }
        
        sum = sum / n;
        
        return sum;
    }
};

int main() {
    // StatisticalAnalyzer a;
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << " average = " << StatisticalAnalyzer::computeAverage(arr, n) << endl;
}









