// https://usaco.org/index.php?page=viewproblem2&cpid=416

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
	setIO("lazy");

	int N, K;
	cin >> N >> K;

	vector<vector<int>> G(N);
	for(auto& elem : G)
	{
		elem.resize(N);
		for(auto& elem2 : elem)
			cin >> elem2;
	}

	vector<vector<int>> v(2*N-1);
	for(auto& elem : v)
		elem.resize(2*N-1);
	
	for(int i=0; i<N; i++)
	{
		int firstPos = (N-1) - i;
		for(int j=0; j<i+1; j++)
			v[i][firstPos+2*j] = G[i-j][j];
	}
	for(int i=N; i<2*N-1; i++)
	{
		int firstPos = i - N + 1;
		for(int j=0; j+firstPos<N; j++)
			v[i][firstPos+2*j] = G[N-j-1][i-N+j+1];
	}

	vector<vector<int>> psV_Row(2*N);
	for(auto& elem : psV_Row)
		elem.resize(2*N, 0);
	for(int i=1; i<2*N; i++)
		for(int j=1; j<2*N; j++)
			psV_Row[i][j] = psV_Row[i][j-1] + v[i-1][j-1];

	vector<vector<int>> psV(2*N);
	for(auto& elem : psV)
		elem.resize(2*N, 0);
	for(int j=1; j<2*N; j++)
		for(int i=1; i<2*N; i++)
			psV[i][j] = psV[i-1][j] + psV_Row[i][j];

	int ans = 0;
	int newK = min(2*K+1, 2*N-1);
	for(int i=newK; i<2*N; i++)
		for(int j=newK; j<2*N; j++)
			ans = max(ans, psV[i][j] - psV[i-newK][j] - psV[i][j-newK] + psV[i-newK][j-newK]);
		
	cout << ans;
}