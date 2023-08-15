// http://www.usaco.org/index.php?page=viewproblem2&cpid=894

#include "bits/stdc++.h"
using namespace std;

int N;
vector<int> v[100010];

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
     
    cin >> N;
    for(int i=0; i<N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    size_t ans = 0;

    for(int i=1; i<=N; i++)
    {
        ans = max(ans, v[i].size());
    }
    
    cout << ++ans;
}
