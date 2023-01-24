#include "bits/stdc++.h"
using namespace std;

long long n;
long long p[25];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("tracing.in", "r", stdin);
	// freopen("tracing.out", "w", stdout);

    cin >> n;

    long long total = 0;
    for(int i=0; i<n; i++)
    {
        cin >> p[i];
        total += p[i];
    }

    long long ans = LONG_LONG_MAX;

    for(int i=0; i<pow(2, 20); i++)
    {
        int k = i;
        long long partSum = 0;

        for(int j=0; j<20; j++)
        {
            bool bInclude = k % 2 == 1;
            if(bInclude)
                partSum += p[j];
            k /= 2;
        }

        ans = min(ans, abs(total - partSum * 2));
    }

    cout << ans;
    
}