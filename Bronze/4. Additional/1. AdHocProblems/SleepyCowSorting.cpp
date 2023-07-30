#include "bits/stdc++.h"
using namespace std;

int N;
int c[110];

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> c[i];
    }

    int ans = 0;

    for(int i=N-1; i>0; i--)
    {
        if(c[i-1] > c[i])
        {
            ans = i;
            break;
        }
    }

    cout << ans;
}