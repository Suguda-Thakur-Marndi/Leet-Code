class Solution {
public:
    class info {
    public:
        int u;
        int cost;
        int stop;

        info(int u, int cost, int stop) {
            this->u = u;
            this->cost = cost;
            this->stop = stop;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        queue<info> q;
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push(info(src, 0, 0));

        while (!q.empty()) {
            info curr = q.front();
            q.pop();

            if (curr.stop > k) continue;

            for (int i = 0; i < flights.size(); i++) {
                if (flights[i][0] == curr.u) {

                    int v = flights[i][1];
                    int wt = flights[i][2];

                    if (dist[v] > curr.cost + wt && curr.stop <= k) {
                        dist[v] = curr.cost + wt;
                        q.push(info(v, dist[v], curr.stop + 1));
                    }
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};