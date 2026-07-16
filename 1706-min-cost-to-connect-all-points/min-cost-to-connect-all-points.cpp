class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<bool> vis(n, false);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, 0});

        int ans = 0;
        int edges = 0;

        while (edges < n) {

            auto [cost, u] = pq.top();
            pq.pop();

            if (vis[u]) continue;

            vis[u] = true;
            ans += cost;
            edges++;

            for (int v = 0; v < n; v++) {

                if (!vis[v]) {

                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    pq.push({dist, v});
                }
            }
        }

        return ans;
    }
};