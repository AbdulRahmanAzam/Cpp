// Kadanes Algorithm
// used to find the maximum of sub array
int maxSubArray(vector<int>& nums) {
        // APPROACH 1 (Kadane's Algorithm)
        int maxi = INT_MIN;
        for(int i =0; i< nums.size(); i++){
            int local = max(nums[i], nums[i]+ local);
            maxi = max(local, maxi);
        }
        return maxi;
    }
