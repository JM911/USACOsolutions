#include "bits/stdc++.h"
using namespace std;

int N;
vector<pair<int, int>> v;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);

    cin >> N;
    for (int i=0; i<N; i++)
    {
        int tmp_1, tmp_2;
        cin >> tmp_1 >> tmp_2;
        v.push_back({tmp_1, tmp_2});
    }

    sort(v.begin(), v.end());

    int curTime = 0;

    for(auto a : v)
    {
        curTime = max(curTime, a.first);
        curTime += a.second;
    }

    cout << curTime;
}