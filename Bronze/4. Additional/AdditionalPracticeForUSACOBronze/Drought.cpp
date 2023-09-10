// http://usaco.org/index.php?page=viewproblem2&cpid=1181

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

int T, N;
long long h[10010];

int main()
{
    setIO("");

    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=0; i<N; i++)
        {
            cin >> h[i];
        }

        if(N%2 == 1)
        {
            long long oddSum = 0;
            long long evenSum = 0;

            for(int i=0; i<N; i++)
            {
                if(i%2 == 0)
                {
                    oddSum += h[i];
                }
                else
                {
                    evenSum += h[i];
                }
            }

            long long result = oddSum - evenSum;
            long long ans = 0;

            bool bCheck = true;
            for(int i=0; i<N; i++)
            {
                if(h[i] < result)
                {
                    bCheck = false;
                    break;
                }
                ans += h[i] - result;
                if(i<N-1)
                {
                    h[i+1] -= h[i] - result;
                    ans += h[i] - result;
                }
            }
            if(result < 0)
                bCheck = false;

            if(bCheck)
                cout << ans << '\n';
            else
                cout << -1 << '\n';
        }

        else
        {
            long long oddSum = 0;
            long long evenSum = 0;
            long long minH = LONG_LONG_MAX;

            for(int i=0; i<N; i++)
            {
                minH = min(minH, h[i]);

                if(i%2 == 1)
                {
                    oddSum += h[i];
                }
                else
                {
                    evenSum += h[i];
                }
            }

            long long result = oddSum - evenSum;
            // long long ans = 0;

            if(result != 0)
            {
                cout << -1 << '\n';
                continue;
            }

            long long canBeAns = LONG_LONG_MAX;
            long long tmp = h[0];
            for(int i=0; i<N-2; i++)
            {
                if(i%2 == 1)
                    continue;

                tmp = h[i+2] - (h[i+1] - tmp);
                canBeAns = min(canBeAns, tmp);                
            }

            if(canBeAns < 0)
            {
                cout << -1 << '\n';
                continue;
            }

            long long target = min(minH, canBeAns);
            long long ans = 0;
            for(int i=0; i<N; i++)
            {
                ans += h[i] - target;
            }

            cout << ans << '\n';
        }
    }
}
