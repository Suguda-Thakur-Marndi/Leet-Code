class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int z=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
                while(z>k){
                    if(nums[l]==0){
                        z--;
                    }
                    l++;
               }
                
            }
            ans=max(ans,i-l+1);
        }
        return ans;
        
    }
};