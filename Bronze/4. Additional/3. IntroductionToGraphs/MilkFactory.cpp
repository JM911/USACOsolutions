// http://www.usaco.org/index.php?page=viewproblem2&cpid=940

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
vector<int> adj[105];

int main()
{
    setIO("factory");

    cin >> N;
    for(int i=1; i<=N-1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[b].push_back(a);
    }

    int ans = INT_MAX;

    for(int i=1; i<=N; i++)
    {
        bool bVisit[105];
        fill(bVisit, bVisit+104, false);

        queue<int> q;
        q.push(i);

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            if(bVisit[cur])
                continue;
            
            bVisit[cur] = true;
            for(auto a : adj[cur])
            {
                q.push(a);
            }
        }

        bool bCheck = true;
        for(int i=1; i<=N; i++)
        {
            if(bVisit[i] == false)
            {
                bCheck = false;
                break;
            }
        }

        if(bCheck)
        {
            ans = min(ans, i);
            break;
        }
    }

    if(ans == INT_MAX)
        ans = -1;

    cout << ans;
}
