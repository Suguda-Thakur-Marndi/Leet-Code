class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
     vector<vector<pair<int,int>>> adj(n);

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
         vector<long long> dist(n, LLONG_MAX);
          vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &[nei, wt] : adj[node]) {
                long long newDist = d + wt;

                if (newDist < dist[nei]) {
                    dist[nei] = newDist;
                    ways[nei] = ways[node];

                    pq.push({newDist, nei});
                }

                else if (newDist == dist[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};

