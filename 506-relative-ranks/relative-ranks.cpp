class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++) {
            players.push_back({score[i], i});
        }
        sort(players.begin(), players.end(), greater<pair<int, int>>());

        vector<string> ans(n);

        for (int i = 0; i < n; i++) {
            int idx = players[i].second;

            if (i == 0)
                ans[idx] = "Gold Medal";
            else if (i == 1)
                ans[idx] = "Silver Medal";
            else if (i == 2)
                ans[idx] = "Bronze Medal";
            else
                ans[idx] = to_string(i + 1);
        }

        return ans;
    }
};