class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;

        int m = grid.size();
        int n = grid[0].size();
        int N = m * n;
        vector<long long> nums(N);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums[i * n + j] = grid[i][j] % MOD;
            }
        }
        vector<long long> prefix(N, 1), suffix(N, 1);

        for (int i = 1; i < N; i++) {
            prefix[i] = (prefix[i - 1] * nums[i - 1]) % MOD;
        }
        for (int i = N - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * nums[i + 1]) % MOD;
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < N; i++) {
            ans[i / n][i % n] = (prefix[i] * suffix[i]) % MOD;
        }

        return ans;
    }
};