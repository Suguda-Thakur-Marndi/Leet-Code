class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());

        int unique = st.size();
        int n = candyType.size();

        return min(unique, n / 2);
    }
};