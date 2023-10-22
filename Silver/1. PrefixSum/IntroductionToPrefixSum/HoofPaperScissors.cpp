// http://www.usaco.org/index.php?page=viewproblem2&cpid=691

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

int N;
char g[100010];
tuple<int, int, int> frontSum[100010];
tuple<int, int, int> backSum[100010];

int MyMaxTuple(tuple<int, int, int> a)
{
    return max(max(get<0>(a), get<1>(a)), get<2>(a));
}

int main()
{
    setIO("hps");

    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> g[i];
    }

    frontSum[0] = {g[0] == 'H', g[0] == 'P', g[0] == 'S'};
    for(int i=1; i<N; i++)
    {
        tuple<int, int, int> prevFrontSum = frontSum[i-1];
        int curH = get<0>(prevFrontSum) + (g[i] == 'H');
        int curP = get<1>(prevFrontSum) + (g[i] == 'P');
        int curS = get<2>(prevFrontSum) + (g[i] == 'S');
        frontSum[i] = {curH, curP, curS};
    }

    backSum[N-1] = {g[N-1] == 'H', g[N-1] == 'P', g[N-1] == 'S'};
    for(int i=N-2; i>=0; i--)
    {
        tuple<int, int, int> prevBackSum = backSum[i+1];
        int curH = get<0>(prevBackSum) + (g[i] == 'H');
        int curP = get<1>(prevBackSum) + (g[i] == 'P');
        int curS = get<2>(prevBackSum) + (g[i] == 'S');
        backSum[i] = {curH, curP, curS};
    }

    int ans = 0;
    for(int i=0; i<N-1; i++)
    {
        ans = max(ans, MyMaxTuple(frontSum[i]) + MyMaxTuple(backSum[i+1]));
    }

    cout << ans;
}
