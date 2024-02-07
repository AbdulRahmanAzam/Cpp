#include <iostream>
using namespace std;

// bool hasSubsetSum(int arr[], int size, int targetSum){
//     // if target is equal to sum then target becomes zero
//     if(targetSum == 0){
//         return 1;
//     }
    
//     // if size array count finishes but target not found
//     if(size == 0 && targetSum != 0){
//         return 0;
//     }
//     // including current elemnt
//     bool include = hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]);
//     // excluding current element
//     bool exclude = hasSubsetSum(arr, size - 1, targetSum);
//     // true if anyone of them is true (excluding the current element)
//     return include || exclude;
// }


bool hasSubsetSum(int arr[], int size, int targetSum){
      // Create a 2D DP array to store intermediate results
    vector<vector<bool>> dp(size + 1, vector<bool>(targetSum + 1, false));
    
    for(int i=0; i<= size; i++){
        dp[i][0] = true;
    }

    //Using the bottom-up approach
    for(int i=1; i<= size; i++){
        for(int j=1; j<= targetSum ;j++){
            // excluding bigger element
            if(arr[i - 1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                // Include the current element or exclude it
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
        }
    }
    cout << dp[size][targetSum] << endl;
    return dp[size][targetSum];
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int targetSum = 12, y;

    int y = hasSubsetSum(arr, n, );

    if(y){
        cout << "Sub set is available" << endl;
    }else{
        cout << "Subset is not available" << endl;
    }
}
