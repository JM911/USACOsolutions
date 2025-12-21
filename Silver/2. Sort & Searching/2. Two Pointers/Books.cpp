// https://codeforces.com/contest/279/problem/B

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;
 
int main()
{
	FASTIO;
 
	int n, t;
	cin >> n >> t;
 
	vector<int> a(n);
	for(auto& elem : a)
		cin >> elem;
 
	int l = 0, r = 0;
	int curTime = 0, ans = 0;
 
	while(r++ < n) {
		curTime += a[r-1];
		while(curTime > t)
			curTime -= a[l++];
		ans = max(ans, r-l);
	}
 
	cout << ans;
}