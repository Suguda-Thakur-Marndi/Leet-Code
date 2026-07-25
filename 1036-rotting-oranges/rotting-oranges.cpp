class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int count = 0;

       
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        if(count == 0) return 0;

        int minutes = 0;

        int d[5] = {0, 1, 0, -1, 0};

        while(!q.empty()){
            int size = q.size();
            bool rotten = false;

            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nx = x + d[j];
                    int ny = y + d[j+1];

                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        count--;
                        rotten = true;
                    }
                }
            }

            if(rotten) minutes++;
        }

        return (count == 0) ? minutes : -1;
    }
};