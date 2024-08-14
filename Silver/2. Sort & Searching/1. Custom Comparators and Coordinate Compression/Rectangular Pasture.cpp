// https://usaco.org/index.php?page=viewproblem2&cpid=1063

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
using ll = long long;

bool MyComp(const pii& a, const pii& b)
{
	return a.second < b.second;
}

int main()
{
	setIO("");

	int N;
	cin >> N;

	map<int, int> xty;
	for(int i=0; i<N; ++i)
	{
		int x, y;
		cin >> x >> y;

		xty.insert({x, y});
	}
	
	map<int, int> ytx;

	int curX = 0;
	for(auto elem : xty)
		ytx.insert({elem.second, curX++});

	vector<vector<int>> v(N, vector<int>(N, 0));

	int curY = 0;
	xty.clear();
	for(auto elem : ytx)
	{
		v[elem.second][curY] = 1;
		xty.insert({elem.second, curY});
		++curY;
	}

	// 2D prefix sum (belowV[a][b]: 0~a 까지 b 이하의 y 값을 가진 점 개수 / aboveV[a][b]: 0~a 까지 b 이상의 y 값을 가진 점 개수)
	
	vector<vector<int>> belowV(N, vector<int>(N, 0));
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
		{
			belowV[i][j] = v[i][j];
			if(i>0) belowV[i][j] += belowV[i-1][j];
			if(j>0) belowV[i][j] += belowV[i][j-1];
			if(i>0 && j>0) belowV[i][j] -= belowV[i-1][j-1];
		}

	vector<vector<int>> aboveV(N, vector<int>(N, 0));
	for(int i=0; i<N; ++i)
		for(int j=N-1; j>=0; --j)
		{
			aboveV[i][j] = v[i][j];
			if(i>0) aboveV[i][j] += aboveV[i-1][j];
			if(j<N-1) aboveV[i][j] += aboveV[i][j+1];
			if(i>0 && j<N-1) aboveV[i][j] -= aboveV[i-1][j+1];
		}

	ll ans = N+1;
	for(auto iter1=xty.begin(); iter1!=xty.end(); ++iter1)
	{
		for(auto iter2=next(iter1); iter2!=xty.end(); ++iter2)
		{
			int top = max(iter1->second, iter2->second);
			int bottom = min(iter1->second, iter2->second);
			int right = max(iter1->first, iter2->first);
			int left = min(iter1->first, iter2->first);

			int belowCount = 0;
			if(bottom>0) belowCount = belowV[right][bottom-1] - belowV[left][bottom-1];
			int aboveCount = 0;
			if(top<N-1) aboveCount = aboveV[right][top+1] - aboveV[left][top+1];

			ans += (belowCount+1) * (aboveCount+1);
		}
	}

	cout << ans;
}