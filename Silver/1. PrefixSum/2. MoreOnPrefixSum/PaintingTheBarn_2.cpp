// https://usaco.org/index.php?page=viewproblem2&cpid=923

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

const int MAX_SIZE = 200;

int main()
{
	setIO("paintbarn");

	int N, K;
	cin >> N >> K;

	// 0. p에 입력 정보 저장(색칠하는 사각형들의 네 끝점)
	vector<vector<int>> p(MAX_SIZE+1, vector<int>(MAX_SIZE+1, 0));
	while(N--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		++p[x2][y2];
		--p[x1][y2];
		--p[x2][y1];
		++p[x1][y1];
	}

	// 1. 입력 정보를 Prefix sum 활용하여 실제 색칠 데이터로 ps에 저장 + 처음 상태부터 K번 덧칠되어있는 칸수를 curK에 저장
	// h에는 K일때 -1, K-1일때 +1로 저장 (h의 의미는 덧칠할 경우 이득이 되는 칸을 +1, 손해가 되는 칸을 -1, 의미 없는 칸을 0으로 놓는 것)
	vector<vector<int>> ps(MAX_SIZE+1, vector<int>(MAX_SIZE+1, 0));
	vector<vector<int>> h(MAX_SIZE+1, vector<int>(MAX_SIZE+1, 0));
	int curK = 0;
	
	for(int i=1; i<=MAX_SIZE; ++i) {
		for(int j=1; j<=MAX_SIZE; ++j) {
			ps[i][j] = p[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];

			if(ps[i][j] == K) {
				++curK;
				h[i][j] = -1;
			}
			if(ps[i][j] == K-1)
				h[i][j] = 1;
		}
	}

	// 2. h의 Prefix sum을 hs에 저장
	vector<vector<int>> hs(MAX_SIZE+1, vector<int>(MAX_SIZE+1, 0));
	for(int i=1; i<=MAX_SIZE; ++i) {
		for(int j=1; j<=MAX_SIZE; ++j) {
			hs[i][j] = h[i][j];
			if(i>0) hs[i][j] += hs[i-1][j];
			if(j>0) hs[i][j] += hs[i][j-1];
			if(i>0 && j>0) hs[i][j] -= hs[i-1][j-1];
		}
	}

	// 3. x=i 또는 y=i 로 경계선을 긋고 해당 경계의 왼쪽/오른쪽 또는 위/아래 영역에 존재하는 사각형들 중 가장 이득이 되는 사각형의 값 도출
	// 가장 이득이 된다는 것은 h 배열에서 +1인 칸을 많이 포함하고, -1인 칸을 적게 포함하는 경우임
	
	// 3-1. 우선 x=i 또는 y=i 줄을 무조건 포함하는 사각형 중 최대를 lMax, rMax, bMax, tMax에 저장 => 여기서 Kadane 알고리즘과 앞에 미리 만든 hs 사용
	vector<int> lMax(MAX_SIZE+1, 0);
	vector<int> rMax(MAX_SIZE+1, 0);
	vector<int> bMax(MAX_SIZE+1, 0);
	vector<int> tMax(MAX_SIZE+1, 0);

	for(int b=0; b<MAX_SIZE; ++b) {
		for(int t=b+1; t<=MAX_SIZE; ++t) {
			int cur = 0;
			for(int i=1; i<=MAX_SIZE; ++i) {
				int added = hs[i][t] - hs[i-1][t] - hs[i][b] + hs[i-1][b];
				cur = max(cur+added, added);
				lMax[i] = max(lMax[i], cur);
			}

			cur = 0;
			for(int i=MAX_SIZE-1; i>=0; --i) {
				int added = hs[i+1][t] - hs[i][t] - hs[i+1][b] + hs[i][b];
				cur = max(cur+added, added);
				rMax[i] = max(rMax[i], cur);
			}
		}
	}

	for(int l=0; l<MAX_SIZE; ++l) {
		for(int r=l+1; r<=MAX_SIZE; ++r) {
			int cur = 0;
			for(int i=1; i<=MAX_SIZE; ++i) {
				int added = hs[r][i] - hs[r][i-1] - hs[l][i] + hs[l][i-1];
				cur = max(cur+added, added);
				bMax[i] = max(bMax[i], cur);
			}

			cur = 0;
			for(int i=MAX_SIZE-1; i>=0; --i) {
				int added = hs[r][i+1] - hs[r][i] - hs[l][i+1] + hs[l][i];
				cur = max(cur+added, added);
				tMax[i] = max(tMax[i], cur);
			}
		}
	}

	// 3-2. 앞에서 구한 것은 해당 행, 열을 무조건 포함할 경우의 최댓값이므로, 전/후를 모두 포함하는 최댓값으로 새로 정리해준다.
	// lMax, bMax의 경우 앞에서 출발하므로 -1 위치의 값과 비교하여 최대를 갱신해 나가면 됨
	// rMax, tMax의 경우 뒤에서 출발하므로 +1 위치의 값과 비교하여 최대를 갱신해 나가면 됨
	for(int i=1; i<=MAX_SIZE; ++i) {
		lMax[i] = max(lMax[i], lMax[i-1]);
		rMax[MAX_SIZE-i] = max(rMax[MAX_SIZE-i], rMax[MAX_SIZE-i+1]);
		bMax[i] = max(bMax[i], bMax[i-1]);
		tMax[MAX_SIZE-i] = max(tMax[MAX_SIZE-i], tMax[MAX_SIZE-i+1]);
	}

	// 4. 추가 색칠 시 최대로 이득 보는 값을 ans에 저장
	// 참고로 lMax[i]는 x=i 경계선의 왼쪽, rMax[i]는 x=i 경계선의 오른쪽 중 최댓값으로 저장했으므로 두 사각형은 겹치지 않음이 보장된다.
	int ans = 0;
	for(int i=0; i<=MAX_SIZE; ++i) {
		ans = max({ans, lMax[i] + rMax[i], bMax[i] + tMax[i]});
	}

	// 처음에 이미 K번 덧칠되어 있던 칸 수 curK에다가 추가로 색칠하여 이득 본 양의 최댓값인 ans를 더하면 최종 결과의 최댓값이 나옴
	cout << ans + curK;
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

int N, K;
int info[201][201];
int paint[201][201];
int h[201][201];
int hps[201][201];

int top_best[201];
int bottom_best[201];
int left_best[201];
int right_best[201];

int main()
{
	setIO("paintbarn");

	cin >> N >> K;
	while(N--)
	{
		int c1, r1, c2, r2;
		cin >> c1 >> r1 >> c2 >> r2;

		++info[r1][c1];
		++info[r2][c2];
		--info[r2][c1];
		--info[r1][c2];
	}

	int curK = 0;
	for(int i=0; i<200; ++i)
	{
		for(int j=0; j<200; ++j)
		{
			if(i==1 && j==1)
				int a=1;
			paint[i][j] = info[i][j];
			if(i>0) paint[i][j] += paint[i-1][j];
			if(j>0) paint[i][j] += paint[i][j-1];
			if(i>0 && j>0) paint[i][j] -= paint[i-1][j-1];

			if(paint[i][j] == K)
			{
				++curK;
				h[i][j] = -1;
			}
			if(paint[i][j] == K-1)
				h[i][j] = 1;
		}
	}

	for(int i=1; i<=200; ++i)
		for(int j=1; j<=200; ++j)
			hps[i][j] = h[i-1][j-1] + hps[i-1][j] + hps[i][j-1] - hps[i-1][j-1];
	
	for(int c1=0; c1<200; ++c1)
	{
		for(int c2=c1+1; c2<=200; ++c2)
		{
			int curMaxSum = 0;
			int addedAmount = 0;
			for(int r=0; r<=200; ++r)
			{
				addedAmount = hps[r][c2] - hps[r][c1];
				if(r>0) addedAmount -= (hps[r-1][c2] - hps[r-1][c1]);
				curMaxSum = max(curMaxSum + addedAmount, addedAmount);
				top_best[r] = max(top_best[r], curMaxSum);
			}

			curMaxSum = 0;
			addedAmount = 0;
			for(int r=200; r>=0; --r)
			{
				addedAmount = hps[r][c2] - hps[r][c1];
				if(r>0) addedAmount -= (hps[r-1][c2] - hps[r-1][c1]);
				curMaxSum = max(curMaxSum + addedAmount, addedAmount);
				bottom_best[r] = max(bottom_best[r], curMaxSum);
			}
		}
	}

	for(int r1=0; r1<200; ++r1)
	{
		for(int r2=r1+1; r2<=200; ++r2)
		{
			int curMaxSum = 0;
			int addedAmount = 0;
			for(int c=0; c<=200; ++c)
			{
				addedAmount = hps[r2][c] - hps[r1][c];
				if(c>0) addedAmount -= (hps[r2][c-1] - hps[r1][c-1]);
				curMaxSum = max(curMaxSum + addedAmount, addedAmount);
				left_best[c] = max(left_best[c], curMaxSum);
			}

			curMaxSum = 0;
			addedAmount = 0;
			for(int c=200; c>=0; --c)
			{
				addedAmount = hps[r2][c] - hps[r1][c];
				if(c>0) addedAmount -= (hps[r2][c-1] - hps[r1][c-1]);
				curMaxSum = max(curMaxSum + addedAmount, addedAmount);
				right_best[c] = max(right_best[c], curMaxSum);
			}
		}
	}

	for(int i=1; i<=200; ++i)
	{
		top_best[i] = max(top_best[i], top_best[i-1]);
		bottom_best[200-i] = max(bottom_best[200-i], bottom_best[201-i]);
		left_best[i] = max(left_best[i], left_best[i-1]);
		right_best[200-i] = max(right_best[200-i], right_best[201-i]);
	}

	int ans = 0;
	for(int i=1; i<=200; ++i)
	{
		ans = max(ans, top_best[i-1] + bottom_best[i]);
		ans = max(ans, left_best[i-1] + right_best[i]);
	}

	cout << ans + curK;
}*/