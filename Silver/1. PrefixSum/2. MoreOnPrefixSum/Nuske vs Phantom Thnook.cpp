// https://atcoder.jp/contests/agc015/tasks/agc015_c

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

const int MX = 2000 + 10;
int N, M, Q;
int board[MX][MX];

int vpf[MX][MX];
int lpf[MX][MX];
int tpf[MX][MX];

int main()
{
	setIO("");

	cin >> N >> M >> Q;
	for(int i=0; i<N; ++i)
	{
		string s;
		cin >> s;
		for(int j=0; j<M; ++j)
			board[i][j] = (s[j] == '1' ? 1 : 0);
	}

	for(int i=1; i<=N; ++i)
		for(int j=1; j<=M; ++j)
			vpf[i][j] = board[i-1][j-1] + vpf[i-1][j] + vpf[i][j-1] - vpf[i-1][j-1];

	for(int i=1; i<=N; ++i)
		for(int j=1; j<=M; ++j)
		{
			lpf[i][j] = lpf[i-1][j] + lpf[i][j-1] - lpf[i-1][j-1];
			tpf[i][j] = tpf[i-1][j] + tpf[i][j-1] - tpf[i-1][j-1];

			if(board[i-1][j-1]==0) continue;

			if(j>1 && board[i-1][j-2]==1)
				++lpf[i][j];
			if(i>1 && board[i-2][j-1]==1)
				++tpf[i][j];
		}	


	while(Q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int curV = vpf[x2][y2];
		if(x1>0) curV -= vpf[x1-1][y2];
		if(y1>0) curV -= vpf[x2][y1-1];
		if(x1>0 && y1>0) curV += vpf[x1-1][y1-1];

		int curL = lpf[x2][y2];
		if(x1>0) curL -= lpf[x1-1][y2];
		curL -= lpf[x2][y1];
		if(x1>0) curL += lpf[x1-1][y1];

		int curT = tpf[x2][y2];
		curT -= tpf[x1][y2];
		if(y1>0) curT -= tpf[x2][y1-1];
		if(y1>0) curT += tpf[x1][y1-1];

		cout << curV - (curL + curT) << '\n';
	}
}