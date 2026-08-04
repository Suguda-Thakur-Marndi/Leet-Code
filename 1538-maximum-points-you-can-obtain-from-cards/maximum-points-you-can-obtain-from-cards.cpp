class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    int s=0;
    for(int i=0;i<k;i++){
         s+=cardPoints[i];
    }
      int ans=s;
      int left=k-1;
      int right=n-1;
      while(left>=0){
        s-=cardPoints[left];
        s+=cardPoints[right];
        ans=max(ans,s);
        left--;
        right--;
    }
    return ans;
    }
};