#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector nums = {2,7,11,15};
    int target  = 9;
    int ans[2] = {0};
    bool done = false;
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != j && nums[i] + nums[j] == target){
                ans[0] = i;
                ans[1] = j;
                done = true;
                break;
            }
        }
        if(done) break;
    }
    
    cout << ans[0] << "  " << ans[1] << endl;
}
