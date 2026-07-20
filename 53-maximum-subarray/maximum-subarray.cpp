class Solution {
public:
    int maxSubArray(vector<int>& nums){
     int n=nums.size();
   int currsum=0;
   int max_sum=INT_MIN;
   for(int i=0;i<n;i++){
    currsum+=nums[i];
    max_sum=max(max_sum,currsum);
    if(currsum<0){
        currsum=0;
    }
   }
   return max_sum;
        
    }
};