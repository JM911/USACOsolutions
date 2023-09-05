// http://www.usaco.org/index.php?page=viewproblem2&cpid=642

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int N;
vector<pair<int, int>> vx;
vector<pair<int, int>> vy;
set<int> s;

bool CompareY(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    setIO("reduce");

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        vx.push_back({i, a});
        vy.push_back({i, b});
    }

    sort(vx.begin(), vx.end(), CompareY);
    sort(vy.begin(), vy.end(), CompareY);

    for(int i=0; i<3; i++)
    {
        s.insert(vx[i].first);
        s.insert(vy[i].first);
        s.insert(vx[N-1-i].first);
        s.insert(vy[N-1-i].first);
    }

    int minArea = INT_MAX;

    for(auto a : s)
    {
        for(auto b : s)
        {
            if(b == a)
                continue;
            for(auto c : s)
            {
                if(c == a || c == b)
                    continue;
                
                int minX = INT_MAX;
                int minY = INT_MAX;
                int maxX = 0;
                int maxY = 0;

                for(int i=0; i<N; i++)
                {
                    if(vx[i].first != a && vx[i].first != b && vx[i].first != c)
                    {
                        minX = min(minX, vx[i].second);
                        maxX = max(maxX, vx[i].second);
                    }
                    if(vy[i].first != a && vy[i].first != b && vy[i].first != c)
                    {
                        minY = min(minY, vy[i].second);
                        maxY = max(maxY, vy[i].second);
                    }
                }

                minArea = min(minArea, (maxX - minX)*(maxY - minY));
            }
        }
    }

    cout << minArea;
}
