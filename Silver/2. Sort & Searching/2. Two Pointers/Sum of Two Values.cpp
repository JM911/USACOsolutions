// https://cses.fi/problemset/task/1640

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

using pii = pair<int, int>;

int main()
{
	setIO("");

	int n, x;
	cin >> n >> x;

	vector<pii> a(n);
	for(int i=0; i<n; ++i) {
		cin >> a[i].first;
		a[i].second = i+1;
	}

	sort(a.begin(), a.end());

	int l = 0, r = n-1;
	while(l < r) {
		int curSum = a[l].first + a[r].first;
		if(curSum == x) {
			cout << a[l].second << ' ' << a[r].second;
			return 0;
		}

		if(curSum < x) ++l;
		else --r;
	}

	cout << "IMPOSSIBLE";
}