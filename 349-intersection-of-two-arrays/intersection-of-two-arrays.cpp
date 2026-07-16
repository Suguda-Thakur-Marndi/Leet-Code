class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> ansSet;

        for(int num : nums2) {
            if(st1.count(num)) {
                ansSet.insert(num);
            }
        }

        vector<int> ans(ansSet.begin(), ansSet.end());

        return ans;
    }
};