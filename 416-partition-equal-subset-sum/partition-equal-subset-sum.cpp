class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int tsum = 0;

        for(int i = 0; i < n; i++) {
            tsum += nums[i];
        }
        if(tsum % 2 != 0) {
            return false;
        }

        int target = tsum / 2;

        vector<bool> dp(target + 1, false);

        dp[0] = true;

        for(int i = 0; i < n; i++) {

            for(int j = target; j >= nums[i]; j--) {

                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};