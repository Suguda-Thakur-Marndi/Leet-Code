class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& sub) {
      
        ans.push_back(sub);

        for (int i = index; i < nums.size(); i++) {
            sub.push_back(nums[i]);              
            solve(i + 1, nums, ans, sub);        
            sub.pop_back();                      
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;

        solve(0, nums, ans, sub);
        return ans;
    }
};
    