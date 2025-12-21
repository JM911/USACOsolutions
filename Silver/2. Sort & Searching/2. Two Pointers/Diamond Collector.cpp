// https://usaco.org/index.php?page=viewproblem2&cpid=643

#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main()
{
	setIO("diamond");

	int N, K;
	cin >> N >> K;

	vector<int> d(N);
	for(auto& elem : d)
		cin >> elem;
	sort(d.begin(), d.end());

	int l2 = 0, r2 = 0;
	int ans = 0;

	while(r2++ < N) {
		while(d[r2-1] - d[l2] > K) ++l2;

		int l1 = 0, r1 = 0;
		while(r1++ < l2) {
			while(d[r1-1] - d[l1] > K) ++l1;
			ans = max(ans, r1-l1 + r2-l2);
		}
	}

	cout << ans;
}