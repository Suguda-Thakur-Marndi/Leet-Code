class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        long long ans = 0;
        int n = nums.size();
        int groups = n / 3;

        for (int i = n - 2, cnt = 0; cnt < groups; i -= 2, cnt++) {
            ans += nums[i];
        }

        return ans;
    }
};