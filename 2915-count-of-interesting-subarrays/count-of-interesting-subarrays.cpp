class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> mp;
        mp[0] = 1;   

        long long ans = 0;
        int pref = 0;

        for (int x : nums) {
            if (x % modulo == k)
                pref++;

            int cur = pref % modulo;

            int target = (cur - k + modulo) % modulo;

            ans += mp[target];

            mp[cur]++;
        }

        return ans;
    }
};