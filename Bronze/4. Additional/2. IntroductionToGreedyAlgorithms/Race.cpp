// http://www.usaco.org/index.php?page=viewproblem2&cpid=989

#include "bits/stdc++.h"
using namespace std;

long long K, N;
long long X[1010];

long long GetMaxVel(long long targetLength)
{
    for(long long i=1; i<100000; i++)
    {
        if( targetLength <= i*(i+1)/2 )
            return i;
    }

    return -1;
}

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    cin >> K >> N;
    for(int i=0; i<N; i++)
    {
        cin >> X[i];
    }   

    long long maxVel = GetMaxVel(K);

    for(int i=0; i<N; i++)
    {
        if(X[i] > maxVel)
            X[i] = maxVel;
    }   

    for(int i=0; i<N; i++)
    {
        long long ans = INT_MAX;
        long long realMaxVel = maxVel;

        while(true)
        {
            if(realMaxVel <= X[i])
                break;
            if(realMaxVel * realMaxVel - (X[i] * (X[i] + 1)) / 2 < K)
                break;
            realMaxVel--;
        }

        long long totalLength = realMaxVel * realMaxVel - (X[i] * (X[i] - 1)) / 2;

        ans = realMaxVel * 2 - X[i];

        if(totalLength < K)
        {
            ans += (K-totalLength) / realMaxVel;
            if((K-totalLength) % realMaxVel != 0)
                ans++;
        }

        cout << ans << '\n';
    }
}
