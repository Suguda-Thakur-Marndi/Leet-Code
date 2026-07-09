class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        int currmin=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]-currmin>k){
                ans++;
                 currmin=nums[i];
            }
         
        }
        return ans;


        
    }
};