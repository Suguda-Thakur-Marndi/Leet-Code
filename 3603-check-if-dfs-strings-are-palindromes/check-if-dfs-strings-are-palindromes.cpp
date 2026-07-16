class Solution {
public:

    vector<vector<int>> adj;
    string dfsStr;

    vector<int> start, ending;

    void dfs(int node, string &s) {

        start[node] = dfsStr.size();

        for(int child : adj[node]) {
            dfs(child, s);
        }

        dfsStr += s[node];

        ending[node] = dfsStr.size() - 1;
    }

    vector<bool> findAnswer(vector<int>& parent, string s) {

        int n = parent.size();

        adj.resize(n);
        start.resize(n);
        ending.resize(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, s);

        string rev = dfsStr;
        reverse(rev.begin(), rev.end());

        const long long base = 31;
        const long long mod = 1e9 + 7;

        vector<long long> power(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * base) % mod;
        }

        vector<long long> hash1(n + 1, 0);
        vector<long long> hash2(n + 1, 0);

        for(int i = 0; i < n; i++) {
            hash1[i + 1] =
                (hash1[i] * base + (dfsStr[i] - 'a' + 1)) % mod;

            hash2[i + 1] =
                (hash2[i] * base + (rev[i] - 'a' + 1)) % mod;
        }

        auto getHash = [&](vector<long long>& h, int l, int r) {

            return (h[r + 1]
                   - (h[l] * power[r - l + 1]) % mod
                   + mod) % mod;
        };

        vector<bool> ans(n);

        for(int i = 0; i < n; i++) {

            int l = start[i];
            int r = ending[i];

            int rl = n - 1 - r;
            int rr = n - 1 - l;

            ans[i] =
                getHash(hash1, l, r)
                ==
                getHash(hash2, rl, rr);
        }

        return ans;
    }
};