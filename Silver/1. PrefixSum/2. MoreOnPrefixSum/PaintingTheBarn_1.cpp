// http://www.usaco.org/index.php?page=viewproblem2&cpid=923

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

#define MY_LENGTH 1000
int N, K;
int p[MY_LENGTH+10][MY_LENGTH+10];
int ps[MY_LENGTH+10][MY_LENGTH+10];

int main()
{
    setIO("paintbarn");

    cin >> N >> K;
    while(N--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        p[x1+1][y1+1]++;
        p[x2+1][y1+1]--;
        p[x1+1][y2+1]--;
        p[x2+1][y2+1]++;
    }

    int ans = 0;
    for(int i=1; i<MY_LENGTH+5; i++)
    {
        for(int j=1; j<MY_LENGTH+5; j++)
        {
            ps[i][j] = p[i][j] + ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1];
            if(ps[i][j] == K)
            {
                ans++;
            }
        }
    }

    cout << ans;
}
