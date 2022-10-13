class Solution
{
    public:
        bool isValid(int i, int j, int n, int m, vector<vector < int>> &grid)
        {
            if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 2 || grid[i][j] == 0)
                return false;
            return true;
        }
    int orangesRotting(vector<vector < int>> &grid)
    {
        int goodOranges = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({ i,
                        j });
                }
                else if(grid[i][j]==1)
                {
                    goodOranges++;
                }
            }
        }
        int ans = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto curr = q.front();
                int i = curr.first, j = curr.second;
                q.pop();
                if (isValid(i + 1, j, n, m, grid))
                {
                    grid[i+1][j]=2;
                    q.push({ i + 1,
                        j });
                    goodOranges--;
                }
                if (isValid(i, j + 1, n, m, grid))
                {
                    grid[i][j+1]=2;
                    q.push({ i,
                        j + 1 });
                    goodOranges--;
                }
                if (isValid(i - 1, j, n, m, grid))
                {
                    grid[i-1][j]=2;
                    q.push({ i - 1,
                        j });
                    goodOranges--;
                }
                if (isValid(i, j - 1, n, m, grid))
                {
                    grid[i][j-1]=2;
                    q.push({ i,
                        j - 1 });
                    goodOranges--;
                }
            }
            ans++;
        }
        if (goodOranges > 0)
            return -1;
        if(ans==0)
            return 0;
        return ans-1;
    }
};