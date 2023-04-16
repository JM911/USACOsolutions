#include "bits/stdc++.h"
using namespace std;

int N, K;
vector<char> v;
int ans;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    cin >> N;
    string tmp;
    cin >> tmp;

    for(int i=0; i<N; i++)
    {
        v.push_back(tmp[i]);
    }

    for(int i=1; i<=N; i++)
    {
        bool bCheck = true;
        unordered_set<string> s;

        for(int j=0; j<N-i+1; j++)
        {
            string str = "";

            for(int k=j; k<j+i; k++)
            {
                str += v[k];
            }

            if(s.count(str) > 0)
            {
                bCheck = false;
                break;
            }
            else
            {
                s.insert(str);
            }
        }

        if(bCheck)
        {
            ans = i;
            break;
        }
    }

    cout << ans;
}