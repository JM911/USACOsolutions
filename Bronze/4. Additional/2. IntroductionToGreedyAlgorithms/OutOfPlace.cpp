// http://www.usaco.org/index.php?page=viewproblem2&cpid=785

#include "bits/stdc++.h"
using namespace std;

int N;
int c[110];

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> c[i];
    }

    vector<int> vc;
    vector<int> vcR;

    for(int i=0; i<N; i++)
    {
        if(i == 0 || c[i-1] != c[i])
        {
            vc.push_back(c[i]);
            vcR.push_back(c[i]);
        }
    }

    int ans = 0;
    int ansR = 0;

    for(int i=1; i<vc.size(); i++)
    {
        if(vc[i-1] > vc[i])
        {
            int tmp = vc[i-1];
            vc[i-1] = vc[i];
            vc[i] = tmp;
            ans++;

            if(i > 1 && vc[i-2] > vc[i-1])
            {
                ans = INT_MAX;
                break;
            }
        }
    }

    for(int i=vcR.size()-1; i>0; i--)
    {
        if(vcR[i-1] > vcR[i])
        {
            int tmp = vcR[i-1];
            vcR[i-1] = vcR[i];
            vcR[i] = tmp;
            ansR++;

            if(i < vcR.size()-1 && vcR[i] > vcR[i+1])
            {
                ansR = INT_MAX;
                break;
            }
        }
    }

    cout << min(ans, ansR);
}