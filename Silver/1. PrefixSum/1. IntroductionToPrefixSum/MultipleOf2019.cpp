// https://atcoder.jp/contests/abc164/tasks/abc164_d

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

string S;
int A[200010];
int M[200010];
int PS[200010];
int MC[2019];

int main()
{
    setIO("");

    cin >> S;

    int n = S.length();
    for(int i=0; i<n; i++)
    {
        const char a = S[i];
        A[i] = atoi(&a);
    }

    int multTen = 1;
    for(int i=n-1; i>=0; i--)
    {
        M[i] = (A[i] * multTen) % 2019;
        multTen = (multTen * 10) % 2019;
    }

    PS[0] = M[0] % 2019;
    MC[PS[0]]++;
    for(int i=1; i<n; i++)
    {
        PS[i] = (PS[i-1] + M[i]) % 2019;
        MC[PS[i]]++;
    }

    long long ans = MC[0];
    for(int i=0; i<2019; i++)
    {
        ans += MC[i] * (MC[i] - 1) / 2;
    }

    cout << ans;
}
