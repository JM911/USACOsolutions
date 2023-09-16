// http://www.usaco.org/index.php?page=viewproblem2&cpid=595

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

using ll = long long;

int N;

int main()
{
    setIO("div7");

    cin >> N;
    vector<ll> id(N);
    for(int i=0; i<N; i++) cin >> id[i];

    vector<ll> preSum(N);
    preSum[0] = id[0] % 7;
    for(int i=1; i<N; i++) preSum[i] = (preSum[i-1] + id[i]) % 7;

    int ans = 0;
    for(int i=0; i<7; i++)
    {
        int firstIdx = -1;
        int lastIdx = -1;
        for(int j=0; j<N; j++)
        {
            if(preSum[j] == i)
            {
                firstIdx = j;
                break;
            }
        }

        for(int j=N-1; j>=0; j--)
        {
            if(preSum[j] == i)
            {
                lastIdx = j;
                break;
            }
        }

        if(firstIdx >= 0 && lastIdx >= 0)
        {
            ans = max(ans, lastIdx - firstIdx);
        }
    }

    if(ans == 0)
    {
        for(auto a : preSum)
        {
            if(a == 0)
            {
                cout << 1;
                return 0;
            }
        }
        cout << 0;
    }
    else
        cout << ans;
}
