class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n);

        for (auto &it : mp) {
            vector<int>& pos = it.second;

            int m = pos.size();

            vector<long long> pref(m);
            pref[0] = pos[0];

            for (int i = 1; i < m; i++) {
                pref[i] = pref[i - 1] + pos[i];
            }

            for (int i = 0; i < m; i++) {
                long long left =
                    1LL * pos[i] * i -
                    (i ? pref[i - 1] : 0);

                long long right =
                    (pref[m - 1] - pref[i]) -
                    1LL * pos[i] * (m - i - 1);

                ans[pos[i]] = left + right;
            }
        }

        return ans;
    }
};