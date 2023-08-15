// http://www.usaco.org/index.php?page=viewproblem2&cpid=1012

#include "bits/stdc++.h"
using namespace std;

int N;
string A, B;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    cin >> N >> A >> B;

    int ans = 0;
    bool bDiff = false;

    for(int i=0; i<A.length(); i++)
    {
        if(A[i] != B[i])
        {
            if(bDiff)
                continue;
            else
            {
                ans++;
                bDiff = true;
            }
        }
        else
        {
            bDiff = false;
        }
    }

    cout << ans;
}