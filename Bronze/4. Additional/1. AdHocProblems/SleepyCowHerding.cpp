#include "bits/stdc++.h"
using namespace std;

int loc[3];

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    for(int i=0; i<3; i++)
    {
        cin >> loc[i];
    }

    sort(loc, loc+3);
    
    int ansMin = min(loc[1] - loc[0] - 1, loc[2] - loc[1] - 1);
    ansMin = min(ansMin, 2);

    int ansMax = max(loc[1] - loc[0] - 1, loc[2] - loc[1] - 1);

    if(ansMin == 0)
    {
        if(ansMax == 1)
            ansMin = 1;
        else if (ansMax > 1)
            ansMin = 2;
    }

    cout << ansMin << '\n' << ansMax;
}