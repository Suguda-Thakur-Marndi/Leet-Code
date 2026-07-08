class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        for (int i = 0; i < n; ) {
            long long start = nums[i];
            int j = i;

            while (j + 1 < n && (long long)nums[j + 1] == (long long)nums[j] + 1) {
                j++;
            }

            if (i == j) {
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(nums[j]));
            }

            i = j + 1;
        }

        return ans;
    }
};