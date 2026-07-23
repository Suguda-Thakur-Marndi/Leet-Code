class Solution {
public:
 void pum(int idex,vector<vector<int>> & ans,vector<int> &pump,vector<int>& nums){
if (idex == nums.size()) {
            ans.push_back(nums);
            return;
        } 

    for(int i=idex;i<nums.size();i++){
        swap(nums[idex],nums[i]);
        pum(idex+1,ans,pump,nums);
         swap(nums[idex], nums[i]); 
        
    }
 }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> pump;
        pum(0,ans,pump,nums);
        return ans;
            
    }
};