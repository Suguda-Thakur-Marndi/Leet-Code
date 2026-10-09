
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto &p : prerequisites) {
            int c = p[0];
            int pre = p[1];

            adj[pre].push_back(c);
            indeg[c]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int neg : adj[node]) {
                indeg[neg]--;

                if (indeg[neg] == 0) {
                    q.push(neg);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        }

        return {};
    }
};
