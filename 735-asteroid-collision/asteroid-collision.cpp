class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> s;

        for (int asteroid : asteroids) {

            bool destroyed = false;

            while (!s.empty() && s.top() > 0 && asteroid < 0) {

                if (s.top() < -asteroid) {
                    s.pop();
                }

                else if (s.top() == -asteroid) {
                    s.pop();
                    destroyed = true;
                    break;
                }

                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                s.push(asteroid);
            }
        }

        vector<int> ans(s.size());

        for (int i = s.size() - 1; i >= 0; i--) {
            ans[i] = s.top();
            s.pop();
        }

        return ans;
    }
};