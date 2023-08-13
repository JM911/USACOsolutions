// http://usaco.org/index.php?page=viewproblem2&cpid=1227

#include "bits/stdc++.h"
using namespace std;

int N;
string s;
char c[200010];

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    // freopen("race.in", "r", stdin);
    // freopen("race.out", "w", stdout);

    cin >> N >> s;
    for(int i=0; i<N; i++)
    {
        c[i] = s[i];
    }

    int n = N / 2;
    int ans = 0;

    bool bFirst = true;
    bool bCurCheck = false;

    for(int i=0; i<n; i++)
    {
        int curDiff = 0;
        bool bOdd = (c[2*i] == 'G');
        bool bEven = (c[2*i+1] == 'G');

        if(bOdd)
            curDiff += 1;
        if(bEven)
            curDiff -= 1;
        
        if(curDiff > 0)
        {
            if(!bCurCheck || bFirst)
            {
                bCurCheck = true;
                ans++;
            }
        }
        else if(curDiff < 0)
        {
            if(bCurCheck || bFirst)
            {
                bCurCheck = false;
                ans++;
            }
        }

        bFirst = false;
    }

    if(!bCurCheck && ans > 0)
        ans--;

    cout << ans;
}
