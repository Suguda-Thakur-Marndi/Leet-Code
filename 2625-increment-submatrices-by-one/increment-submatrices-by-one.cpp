class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n + 1, 0));

        for (auto &q : queries) {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];

            for (int r = r1; r <= r2; r++) {
                ans[r][c1]++;

                if (c2 + 1 < n)
                    ans[r][c2 + 1]--;
            }
        }

        vector<vector<int>> res(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            int prefix = 0;
            for (int j = 0; j < n; j++) {
                prefix += ans[i][j];
                res[i][j] = prefix;
            }
        }

        return res;
    }
};