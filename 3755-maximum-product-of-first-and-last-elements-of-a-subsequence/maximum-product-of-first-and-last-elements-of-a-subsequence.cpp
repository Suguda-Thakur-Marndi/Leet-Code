class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();

        long long ans = LLONG_MIN;

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        for (int j = m - 1; j < n; j++) {
            int startIdx = j - m + 1;

            mx = max(mx, (long long)nums[startIdx]);
            mn = min(mn, (long long)nums[startIdx]);

            ans = max(ans, mx * nums[j]);
            ans = max(ans, mn * nums[j]);
        }

        return ans;
    }
};