// https://atcoder.jp/contests/agc015/tasks/agc015_c

// 복습하고 개인 해설 추가한 코드로 새로 갱신함 (처음 풀이 코드는 맨 아래에 주석처리)
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

	// 핵심 아이디어: 덩어리 수 = 파란 블록 수 - 파란 블록이 양쪽(좌우 또는 상하)에 붙어있는 경계선의 수
	// 파란 블록이 인접한 경계선의 수 = 왼쪽에 파란 블록과 맞닿아 있는 파란 블록 수(=좌우 경계선 수) + 위쪽에 파란 블록과 맞닿아 있는 파란 블록 수(상하 경계선 수)
	// 따라서 주어진 구역에서의 위 세 가지 조건 파란 블록 수를 계산할 수 있는 환경만 갖춰지면 됨.
	// 이때 2D Prefix sum을 사용하면 파란 블록 수를 계산하는 시간 복잡도는 O(1)이 되도록 할 수 있음
	
	// 핵심 아이디어의 증명
	// 하나의 덩어리에 파란 블록을 추가해 나간다고 생각하면, 블록 한 개 추가 시 무조건 경계선 하나만 추가될 수 있음
	// 이유1 - 경계선 추가하지 않고 블록 추가는 불가능 (하나의 덩어리가 아님)
	// 이유2 - 경계선 2개 이상? 해당 경계선에 붙어있는 두 파란 블록은 이미 한 덩어리였으므로 경로가 존재할 것임. 근데 새로운 블록이 추가됨으로써 새로운 경로가 생겨버린다. 이는 문제 조건에 위배
	// 따라서 하나의 덩어리에는 파란 블록 수 - 경계선 수 = 1 임을 확신할 수 있음 => 이를 통해 전체 덩어리를 계산 가능

	int N, M, Q;
	cin >> N >> M >> Q;

	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<vector<int>> lboard(N, vector<int>(M, 0));
	vector<vector<int>> tboard(N, vector<int>(M, 0));
	
	for(int i=0; i<N; ++i) {
		string s;
		cin >> s;
		for(int j=0; j<M; ++j)
			board[i][j] = s[j] - '0';
	}

	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			if(board[i][j] == 0) continue;
			if(j>0 && board[i][j-1]==1) lboard[i][j] = 1;
			if(i>0 && board[i-1][j]==1) tboard[i][j] = 1;
		}
	}

	vector<vector<int>> ps(N+1, vector<int>(M+1, 0));
	vector<vector<int>> lps(N+1, vector<int>(M+1, 0));
	vector<vector<int>> tps(N+1, vector<int>(M+1, 0));

	for(int i=1; i<=N; ++i) {
		for(int j=1; j<=M; ++j) {
			ps[i][j] = board[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
			lps[i][j] = lboard[i-1][j-1] + lps[i-1][j] + lps[i][j-1] - lps[i-1][j-1];
			tps[i][j] = tboard[i-1][j-1] + tps[i-1][j] + tps[i][j-1] - tps[i-1][j-1];
		}
	}

	while(Q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int bNum = ps[x2][y2] - ps[x1-1][y2] - ps[x2][y1-1] + ps[x1-1][y1-1];
		int lNum = lps[x2][y2] - lps[x1-1][y2] - lps[x2][y1] + lps[x1-1][y1];
		int tNum = tps[x2][y2] - tps[x1][y2] - tps[x2][y1-1] + tps[x1][y1-1];

		cout << bNum - lNum - tNum << '\n';
	}
}


/*
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
*/