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

	ll ans = N+1;	// 사각형에 소가 0마리 인 경우 1개 + 소가 1마리인 경우 N개를 우선 세팅
	// 이후 소가 2마리 이상인 경우를 아래 반복문에서 더해준다.
	for(auto iter1=xty.begin(); iter1!=xty.end(); ++iter1)
	{
		for(auto iter2=next(iter1); iter2!=xty.end(); ++iter2)
		{
			// 우선 무조건 포함할 소 두 마리를 조합으로 선택하여 해당 소들이 딱 맞게 포함되는 사각형의 끝점 값들을 구한다.
			int top = max(iter1->second, iter2->second);
			int bottom = min(iter1->second, iter2->second);
			int right = max(iter1->first, iter2->first);
			int left = min(iter1->first, iter2->first);

			// 이후 이 사각형을 위, 아래로만 확장하여 추가로 포함할 수 있는 소의 숫자를 구한다.
			// 두 점을 선택하는 순서를 x 기준으로 순회하는 중이므로 y 방향으로의 확장만 고려하는 것 
			// (x 방향으로 확장하지 않음으로써 중복 카운트 방지, y 방향으로 확장함으로써 모든 경우 체크 보장)
			int belowCount = 0;
			if(bottom>0) belowCount = belowV[right][bottom-1] - belowV[left][bottom-1];
			int aboveCount = 0;
			if(top<N-1) aboveCount = aboveV[right][top+1] - aboveV[left][top+1];

			// 위로 확장 * 아래로 확장하는 경우의 수를 모두 구함 (확장을 안하는 경우까지 있으므로 +1을 하여 곱해준다)
			ans += (belowCount+1) * (aboveCount+1);
		}
	}

	cout << ans;
}