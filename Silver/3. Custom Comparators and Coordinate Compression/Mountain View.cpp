// https://usaco.org/index.php?page=viewproblem2&cpid=896

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

bool MyComp(const pii& a, const pii& b)
{
	if(a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	setIO("mountains");

	int N;
	cin >> N;

	int ans = N;
	vector<pii> mp;
	while(N--)
	{
		int x, y;
		cin >> x >> y;

		mp.push_back({y-x, x+y});
	}
	sort(mp.begin(), mp.end(), MyComp);

	int curM = mp[0].first;
	for(int i=1; i<mp.size(); ++i)
	{
		if(mp[i].first > curM)
			curM = mp[i].first;
		else
			--ans;
	}

	cout << ans;
}