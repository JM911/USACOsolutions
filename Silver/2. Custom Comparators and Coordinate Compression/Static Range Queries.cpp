// https://codeforces.com/gym/102951/problem/D

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
const ll MX = 1e9 + 10;

int main()
{
	setIO("");

	int N, Q;
	cin >> N >> Q;
	
	map<ll, ll> m;
	while(N--)
	{
		ll l, r;
		ll v;
		cin >> l >> r >> v;

		if(m.count(l) > 0)
			m[l] += v;
		else
			m.insert({l, v});
		
		if(m.count(r) > 0)
			m[r] -= v;
		else
			m.insert({r, -v});
	}

	ll prevIdx = 0;
	ll prevPS = 0;
	ll curV = 0;
	
	map<ll, ll> newM;
	newM.insert({0, 0});
	for(auto elem : m)
	{
		ll newPS = prevPS + curV * (ll)(elem.first - prevIdx);
		newM.insert({elem.first, newPS});
		
		prevPS = newPS;
		prevIdx = elem.first;
		curV += elem.second;
	}
	newM.insert({MX, 0});// curV * (ll)(MX - prevIdx)});

	while(Q--)
	{
		ll l, r;
		cin >> l >> r;

		auto iterLL = newM.lower_bound(l);
		auto iterPLL = newM.begin();
		
		if(iterLL != newM.begin())
			iterPLL = prev(iterLL);
		
		ll d = (ll)(iterLL->first - iterPLL->first);
		ll psl = iterLL->second;
		if(d != 0)
			psl = iterPLL->second + (iterLL->second - iterPLL->second) / d * (ll)(l - iterPLL->first);
		if(iterLL->first == MX)
			psl = iterPLL->second;
		
		auto iterLR = newM.lower_bound(r);
		auto iterPLR = newM.begin();

		if(iterLR != newM.begin())
			iterPLR = prev(iterLR);
		
		d = (ll)(iterLR->first - iterPLR->first);
		ll psr = iterLR->second;
		if(d != 0)
			psr = iterPLR->second + (iterLR->second - iterPLR->second) / d * (ll)(r - iterPLR->first);
		if(iterLR->first == MX)
			psr = iterPLR->second;

		cout << psr - psl << '\n';
	}
}