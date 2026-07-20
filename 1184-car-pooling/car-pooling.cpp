class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<int> road(1001, 0);

        
        for (int i = 0; i < trips.size(); i++) {

            int passengers = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            road[from] += passengers;
            road[to] -= passengers;
        }

        int passengerCount = 0;

        for (int i = 0; i <= 1000; i++) {

            passengerCount += road[i];

            if (passengerCount > capacity) {
                return false;
            }
        }

        return true;
    }
};