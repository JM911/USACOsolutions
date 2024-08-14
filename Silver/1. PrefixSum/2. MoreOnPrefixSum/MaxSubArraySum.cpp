// https://cses.fi/problemset/task/1643/

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
int n;
vector<ll> x;

int main()
{
    setIO("");

    cin >> n;
    x.resize(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }

    vector<ll> ps, psMin;
    ps.push_back(x[0]);
    psMin.push_back(min((ll)0, x[0]));
    ll ans = x[0];

    for(int i=1; i<n; i++)
    {
        ps.push_back(ps[i-1] + x[i]);
        psMin.push_back(min(psMin[i-1], ps[i]));
        ans = max(ans, ps[i] - psMin[i-1]);
    }

    cout << ans;
}
