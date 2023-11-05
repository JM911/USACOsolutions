// https://cses.fi/problemset/task/1652

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

int n, q;
char f[1010][1010];
int fNum[1010][1010];
int psLine[1010][1010];
int psTotal[1010][1010];

int main()
{
    setIO("");

    cin >> n >> q;
    for(int i=1; i<=n; i++)
    {
        string tmpLine;
        cin >> tmpLine;

        for(int j=1; j<=n; j++)
        {
            f[i][j] = tmpLine[j-1];
            fNum[i][j] = (f[i][j] == '*' ? 1 : 0);
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            psLine[i][j] = psLine[i][j-1] + fNum[i][j];
            psTotal[i][j] = psTotal[i-1][j] + psLine[i][j];
        }
    }

    while(q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = (psTotal[y2][x2] - psTotal[y2][x1-1]) - (psTotal[y1-1][x2] - psTotal[y1-1][x1-1]);
        cout << ans << '\n';
    }
}
