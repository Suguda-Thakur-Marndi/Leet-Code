class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s[i] == '*');
        }

        vector<int> leftCandle(n, -1);
        vector<int> rightCandle(n, -1);

        int last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') last = i;
            leftCandle[i] = last;
        }

        last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '|') last = i;
            rightCandle[i] = last;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int start = rightCandle[l];
            int end = leftCandle[r];

            if (start == -1 || end == -1 || start >= end) {
                ans.push_back(0);
            } else {
                ans.push_back(prefix[end] - prefix[start]);
            }
        }

        return ans;
    }
};