// https://cses.fi/problemset/task/1641

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

int MySearch(const vector<pii>& a, int target, int st, int en) {
	if(en - st < 1) return -1;
	if(en - st == 1) {
		if(target == a[st].first) return st;
		return -1;
	}

	int mid = (st + en) / 2;
	if(a[mid].first == target) return mid;

	if(target < a[mid].first) return MySearch(a, target, st, mid);
	else return MySearch(a, target, mid+1, en);
}

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

	for(int i=0; i<n-2; ++i) {
		for(int j=i+1; j<n-1; ++j) {
			int target = x - a[i].first - a[j].first;
			if(target < a[j+1].first || target > a[n-1].first) continue;
			int k = MySearch(a, target, j+1, n);
			if(k >= 0) {
				cout << a[i].second << ' ' << a[j].second << ' ' << a[k].second;
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE";
}