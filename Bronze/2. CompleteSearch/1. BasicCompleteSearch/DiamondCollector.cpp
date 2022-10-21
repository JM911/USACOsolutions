#include "bits/stdc++.h"
using namespace std;

int N, K;
int Diamond[20100];

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        Diamond[tmp]++;
    }

    int sum = 0;

    for(int i = 1; i <= 1 + K; i++)
    {
        sum += Diamond[i];
    }

    int ans = sum;

    for(int j = 1; j <= 10000; j++)
    {
        sum -= Diamond[j];
        sum += Diamond[j + K + 1];

        ans = max(ans, sum);
    }

    cout << ans;
}