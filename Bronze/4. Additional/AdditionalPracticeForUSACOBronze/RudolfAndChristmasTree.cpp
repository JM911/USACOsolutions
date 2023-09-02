// https://codeforces.com/contest/1846/problem/D

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

int t, n, d, h;
int y[200010];

int main()
{
    setIO("");

    cin >> t;

    while(t--)
    {
        cin >> n >> d >> h;
        for(int i=0; i<n; i++)
        {
            cin >> y[i];
        }

        double one = 0.5 * d * h;
        double ans = one * n;

        for(int i=0; i<n-1; i++)
        {
            if(y[i+1]-y[i] < h)
            {
                double diff = h - (y[i+1] - y[i]);
                //double blockedRate = double(diff) / h;
                double blockedArea = 0.5 * d * diff * diff / h;
                ans -= blockedArea;
            }
        }

        cout << fixed << setprecision(7) << ans << '\n';
    }
}
