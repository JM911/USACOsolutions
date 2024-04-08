// https://usaco.org/index.php?page=viewproblem2&cpid=787

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
using pll = pair<ll, ll>;

int main()
{
	setIO("rental");

	int N, M, R;
	cin >> N >> M >> R;

	vector<ll> c(N);
	for(auto& elem : c)
		cin >> elem;
	sort(c.begin(), c.end());
	
	vector<pll> pq(M);
	for(auto& elem : pq)
		cin >> elem.second >> elem.first;
	sort(pq.begin(), pq.end(), greater<pll>());

	vector<ll> r(R);
	for(auto& elem : r)
		cin >> elem;
	sort(r.begin(), r.end(), greater<ll>());

	ll totalMilk = 0;
	for(auto elem : c)
		totalMilk += elem;


	int pqIdx = 0;
	vector<ll> v(N+1, 0);	// i ~ N-1 까지 소를 우유에 썼을 때 얻는 최대 이익
	ll remainSpace = pq[pqIdx].second;

	for(int i=N-1; i>=0; --i)
	{
		ll curMilk = c[i];
		ll curAddedProfit = 0;
		while(curMilk > 0 && pqIdx < M)
		{
			if(curMilk > remainSpace)
			{
				curAddedProfit += pq[pqIdx].first * remainSpace;
				curMilk -= remainSpace;
				++pqIdx;
				if(pqIdx < M)
					remainSpace = pq[pqIdx].second;
			}
			else
			{
				curAddedProfit += pq[pqIdx].first * curMilk;
				remainSpace -= curMilk;
				curMilk = 0;
			}
		}

		v[i] = v[i+1] + curAddedProfit;
	}

	vector<ll> v2(R+1, 0);	// 0 ~ i-1 까지 소를 렌트할 때 얻는 누적 이익
	for(int i=1; i<=R; ++i)
		v2[i] = v2[i-1] + r[i-1];


	int idxMax = min(N+1, R+1);
	int vIdx = v.size() - 1;
	ll ans = v[0];

	for(int i=0; i<idxMax; ++i)
		ans = max(ans, v[i] + v2[i]);

	cout << ans;
}