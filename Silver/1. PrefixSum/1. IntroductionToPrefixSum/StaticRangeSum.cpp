// https://judge.yosupo.jp/problem/static_range_sum

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

int N, Q;
vector<ll> a;

int main()
{
    setIO("");

    cin >> N >> Q;
    for(int i=0; i<N; i++)
    {
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    vector<ll> accSum;
    accSum.push_back(0);
    for(int i=1; i<=N; i++)
    {
        accSum.push_back(accSum[i-1] + a[i-1]);
    }

    while(Q--)
    {
        int l, r;
        cin >> l >> r;

        cout << accSum[r] - accSum[l] << '\n';
    }
}
