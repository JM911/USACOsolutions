// https://cses.fi/problemset/task/1163/

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

int main()
{
	setIO("");

	int x, n;
	cin >> x >> n;

	set<int> s;
	s.insert(0);
	s.insert(x);

	multiset<int> ms;
	ms.insert(x);
	
	while(n--) {
		int p;
		cin >> p;

		auto iterR = s.lower_bound(p);
		auto iterL = prev(iterR);
		int r = *iterR;
		int l = *iterL;

		int prevDist = r - l;
		int nextDist1 = r - p;
		int nextDist2 = p - l;

		s.insert(p);
		ms.erase(ms.find(prevDist));
		ms.insert(nextDist1);
		ms.insert(nextDist2);

		cout << *prev(ms.end()) << ' ';
	}
}