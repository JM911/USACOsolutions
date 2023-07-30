#include "bits/stdc++.h"
using namespace std;

struct gridMinMax
{
    int minX;
    int minY;
    int maxX;
    int maxY;
};

int N;
int grid[12][12];
unordered_map<int, gridMinMax> m;
unordered_set<int> colors;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    cin >> N;

    for(int i=0; i<N; i++)
    {
        string s;
        cin >> s;
        for(int j=0; j<N; j++)
        {
            const char curNum = s[j];
            grid[i][j] = atoi(&curNum);

            if(grid[i][j] == 0) continue;

            colors.insert(grid[i][j]);

            if(m.find(grid[i][j]) == m.end())
            {
                m.insert({grid[i][j], gridMinMax{i, j, i, j}});
            }
            else
            {
                gridMinMax curMinMax = m[grid[i][j]];
                int curMinX = min(i, curMinMax.minX);
                int curMinY = min(j, curMinMax.minY);
                int curMaxX = max(i, curMinMax.maxX);
                int curMaxY = max(j, curMinMax.maxY);
                m[grid[i][j]] = gridMinMax{curMinX, curMinY, curMaxX, curMaxY};
            }
        }
    }

    for(int c=1; c<=9; c++)
    {
        if(m.find(c) == m.end()) continue;

        for(int i=m[c].minX; i<=m[c].maxX; i++)
        {
            for(int j=m[c].minY; j<=m[c].maxY; j++)
            {
                if(grid[i][j] != c && grid[i][j] != 0)
                    colors.erase(grid[i][j]);
            }
        }
    }

    cout << colors.size();
}