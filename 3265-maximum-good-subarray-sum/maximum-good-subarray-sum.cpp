class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> mp;

        long long prefix = 0;
        long long ans = LLONG_MIN;

        for (int x : nums) {
            long long curPrefix = prefix + x;

            if (mp.count(x - k))
                ans = max(ans, curPrefix - mp[x - k]);

            if (mp.count(x + k))
                ans = max(ans, curPrefix - mp[x + k]);

            if (!mp.count(x))
                mp[x] = prefix;
            else
                mp[x] = min(mp[x], prefix);

            prefix = curPrefix;
        }

        return ans == LLONG_MIN ? 0 : ans;
    }
};