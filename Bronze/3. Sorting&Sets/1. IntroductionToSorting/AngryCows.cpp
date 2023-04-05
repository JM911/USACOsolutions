#include "bits/stdc++.h"
using namespace std;

int N;
int x[110];

bool IsInRange(int targetNum, const vector<pair<int, int>>& boundVec)
{
    for(auto a : boundVec)
    {
        if(targetNum >= a.first && targetNum <= a.second)
            return true;
    }

    return false;
}

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> x[i];
    }

    int ans = 0;

    for(int i=0; i<N; i++)
    {
        vector<pair<int, int>> boundary;
        bool bCheck[110];
        fill(bCheck, bCheck+100, false);

        bCheck[i] = true;
        boundary.push_back({x[i] - 1, x[i] + 1});
        int step = 1;

        while(!boundary.empty())
        {
            step++;
            vector<pair<int, int>> newBoundary;
            for(int j=0; j<N; j++)
            {
                if(bCheck[j])
                    continue;
                if(IsInRange(x[j], boundary))
                {
                    bCheck[j] = true;
                    newBoundary.push_back({x[j] - step, x[j] + step});
                }
            }
            boundary = newBoundary;
        }
        
        int curAns = 0;
        for(int j=0; j<N; j++)
        {
            if(bCheck[j])
                curAns++;
        }
        
        ans = max(ans, curAns);
    }

    cout << ans;
}