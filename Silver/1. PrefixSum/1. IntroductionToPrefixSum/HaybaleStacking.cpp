// https://www.spoj.com/problems/HAYBALE/

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
int d[1000010];

int main()
{
    setIO("");

    cin >> N >> K;
    for(int i=0; i<K; i++)
    {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b+1]--;
    }

    vector<int> s(N);
    s[0] = d[0];
    for(int i=1; i<N; i++) s[i] = s[i-1] + d[i];

    sort(s.begin(), s.end());

    cout << s[(N-1)/2];
}
