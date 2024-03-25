// https://codeforces.com/gym/104114/problem/N

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
ll m;

int main()
{
	setIO("");

	cin >> n >> m;
	vector<ll> s(n);

	for(auto& elem : s)
		cin >> elem;

	vector<ll> a(n), b(n);
	for(int i=0; i<n; ++i)
	{
		a[i] = s[i] - i * m;
		b[i] = s[i] - (n-i-1) * m;
	}

	vector<ll> aMax(n), bMax(n);
	aMax[n-1] = a[n-1];
	bMax[0] = b[0];
	for(int i=1; i<n; ++i)
	{
		aMax[n-i-1] = max(aMax[n-i], a[n-i-1]);
		bMax[i] = max(bMax[i-1], b[i]);
	}

	for(int i=0; i<n; ++i)
	{
		cout << max({s[i], aMax[i]+m*i, bMax[i]+m*(n-i-1)}) << ' ';
	}
}