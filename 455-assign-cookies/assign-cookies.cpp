class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort (s.begin(),s.end());
        int i=0;
        int j=0;
        int cout=0;
        while(i < g.size() && j< s.size()){
            if(s[j]>=g[i]){
                cout++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return cout;
        
    }
};