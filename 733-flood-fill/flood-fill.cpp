class Solution {
public:

    void dfs(vector<vector<int>>& image, int row, int col,
             int oldColor, int newColor)
    {
        int m = image.size();
        int n = image[0].size();

        image[row][col] = newColor;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               image[nr][nc] == oldColor)
            {
                dfs(image, nr, nc, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};