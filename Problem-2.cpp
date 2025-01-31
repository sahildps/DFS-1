/*
TC : O (m*n)
SC : O (m*n)
*/
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        if (mat.size() == 0 || mat.empty())
        {
            return {};
        }

        queue<vector<int>> store;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // U D L R
        int m = mat.size(), n = mat[0].size();

        // keep track of 0's and 1's
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    vector<int> temp = {i, j};
                    store.push(temp);
                }
                else
                { // if value is 1 then update to -1
                    mat[i][j] = mat[i][j] * (-1);
                }
            }
        }

        while (!store.empty())
        {
            vector<int> cur = store.front();

            for (int i = 0; i < dirs.size(); i++)
            {
                int nr = cur[0] + dirs[i][0];
                int nc = cur[1] + dirs[i][1];

                // update for valid cell which is not yet been visited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1)
                {
                    mat[nr][nc] = mat[cur[0]][cur[1]] + 1;
                    vector<int> temp = {nr, nc};
                    store.push(temp);
                }
            }
            store.pop();
        }

        return mat;
    }
};