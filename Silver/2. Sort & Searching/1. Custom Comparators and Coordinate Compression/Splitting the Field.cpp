// https://usaco.org/index.php?page=viewproblem2&cpid=645

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
using pii = pair<int, int>;
const int INF = 1e9 + 10;

bool MyCompX(const pii& a, const pii& b)
{
	return a.first < b.first;
}

bool MyCompY(const pii& a, const pii& b)
{
	return a.second < b.second;
}
int main()
{
	setIO("split");

	int N;
	cin >> N;
	
	vector<pii> v(N);
	int minX=INF, maxX=0, minY=INF, maxY=0;
	for(auto& elem : v)
	{
		cin >> elem.first >> elem.second;
		minX = min(minX, elem.first);
		maxX = max(maxX, elem.first);
		minY = min(minY, elem.second);
		maxY = max(maxY, elem.second);
	}
	
	ll firstArea = (ll)(maxX - minX) * (ll)(maxY - minY);

	sort(v.begin(), v.end(), MyCompX);

	vector<int> leftMinY(N), leftMaxY(N), rightMinY(N), rightMaxY(N);
	leftMinY[0] = v[0].second;
	leftMaxY[0] = v[0].second;
	rightMinY[N-1] = v[N-1].second;
	rightMaxY[N-1] = v[N-1].second;

	for(int i=1; i<N; ++i)
	{
		leftMinY[i] = min(leftMinY[i-1], v[i].second);
		leftMaxY[i] = max(leftMaxY[i-1], v[i].second);
		rightMinY[N-1-i] = min(rightMinY[N-i], v[N-i-1].second);
		rightMaxY[N-1-i] = max(rightMaxY[N-i], v[N-i-1].second);
	}

	ll secondArea = 1e18+10;
	int curX = 0;
	for(int i=0; i<N-1; i++)
	{
		// if(v[i].first == curX) continue;

		// curX = v[i].first;
		ll area1 = (ll)(leftMaxY[i] - leftMinY[i]) * (ll)(v[i].first - v[0].first);
		ll area2 = (ll)(rightMaxY[i+1] - rightMinY[i+1]) * (ll)(v[N-1].first - v[i+1].first);
		secondArea = min(secondArea, area1+area2);
	}


	sort(v.begin(), v.end(), MyCompY);

	vector<int> bottomMinY(N), bottomMaxY(N), topMinY(N), topMaxY(N);
	bottomMinY[0] = v[0].first;
	bottomMaxY[0] = v[0].first;
	topMinY[N-1] = v[N-1].first;
	topMaxY[N-1] = v[N-1].first;

	for(int i=1; i<N; ++i)
	{
		bottomMinY[i] = min(bottomMinY[i-1], v[i].first);
		bottomMaxY[i] = max(bottomMaxY[i-1], v[i].first);
		topMinY[N-1-i] = min(topMinY[N-i], v[N-i-1].first);
		topMaxY[N-1-i] = max(topMaxY[N-i], v[N-i-1].first);
	}

	int curY = 0;
	for(int i=0; i<N-1; i++)
	{
		// if(v[i].second == curY) continue;

		// curY = v[i].second;
		ll area1 = (ll)(bottomMaxY[i] - bottomMinY[i]) * (ll)(v[i].second - v[0].second);
		ll area2 = (ll)(topMaxY[i+1] - topMinY[i+1]) * (ll)(v[N-1].second - v[i+1].second);
		secondArea = min(secondArea, area1+area2);
	}

	cout << firstArea - secondArea;
}