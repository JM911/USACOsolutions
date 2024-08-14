// http://www.usaco.org/index.php?page=viewproblem2&cpid=572

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

int N, Q;
vector<int> cowNum[5];

int main()
{
    setIO("bcount");

    cin >> N >> Q;
    cowNum[1].push_back(0);
    cowNum[2].push_back(0);
    cowNum[3].push_back(0);

    for(int i=1; i<=N; i++)
    {
        int c;
        cin >> c;
        
        for(int j=1; j<=3; j++)
        {
            cowNum[j].push_back(c==j ? cowNum[j][i-1]+1 : cowNum[j][i-1]);
        }
    }

    while(Q--)
    {
        int a, b;
        cin >> a >> b;

        cout << cowNum[1][b] - cowNum[1][a-1] << ' '
            << cowNum[2][b] - cowNum[2][a-1] << ' '
            << cowNum[3][b] - cowNum[3][a-1] << '\n';
    }
}
