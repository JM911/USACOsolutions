// https://codeforces.com/contest/1826/problem/D

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

int t, n;
ll b[100010];

bool MyCompare(pair<ll, ll> a, pair<ll, ll> b)
{
    if(a.second == b.second)
    {
        return a.first > b.first;
    }

    return a.second > b.second;
}

int main()
{
    setIO("");

    cin >> t;
    while(t--)
    {
        vector<pair<ll, ll>> v;

        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> b[i];
            v.push_back({i, b[i]});
        }

        vector<ll> brr, bll;
        for(int i=0; i<n; i++)
        {
            brr.push_back(b[i]+i);
            bll.push_back(b[i]-i);
        }

        vector<ll> brrMax(n), bllMax(n);
        brrMax[0] = brr[0];
        bllMax[n-1] = bll[n-1];
        for(int i=1; i<n; i++)
        {
            brrMax[i] = max(brr[i], brrMax[i-1]);

            // int l = n-i-1;
            // bllMax.push_front(max(bll[l], bll[l+1]));
        }
        for(int i=n-2; i>=0; i--)
        {
            bllMax[i] = max(bll[i], bllMax[i+1]);
        }

        ll ans = 0;
        for(int i=1; i<n-1; i++)
        {
            ll curSum = brrMax[i-1] + b[i] + bllMax[i+1];
            ans = max(ans, curSum);
        }

        cout << ans << '\n';
    }
}
