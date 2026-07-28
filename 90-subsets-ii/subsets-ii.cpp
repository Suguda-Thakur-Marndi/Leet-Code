class Solution {
public:
    vector<vector<int>> a;
    vector<int> t;

    void solve(vector<int>& nums, int idx) {
        a.push_back(t);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            t.push_back(nums[i]);
            solve(nums, i + 1);
            t.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return a;
    }
};