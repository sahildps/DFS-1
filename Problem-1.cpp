/*
TC : O (m*n)
SC : O (m*n)
*/
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image.size() == 0 || image.empty())
        {
            return {};
        }

        // keep track of old color
        int oldColor = image[sr][sc];
        // to process next elements
        queue<vector<int>> store;
        int m = image.size(), n = image[0].size();
        // to check all adjacent
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // L R U D
        store.push({sr, sc});
        // to keep track of visited indexes
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        image[sr][sc] = color;

        while (!store.empty())
        {
            vector<int> curr = store.front();

            for (int i = 0; i < dirs.size(); i++)
            {
                int nr = curr[0] + dirs[i][0];
                int nc = curr[1] + dirs[i][1];
                // check if it's a valid index, not visited and if it holds the same value as old color
                if (nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && image[nr][nc] == oldColor && visited[nr][nc] != 1)
                {
                    visited[nr][nc] = 1;
                    image[nr][nc] = color;
                    store.push({nr, nc});
                }
            }
            store.pop();
        }

        return image;
    }
};