#include "bits/stdc++.h"
using namespace std;

int N, M;
int s[30], t[30], c[30];
int a[30], b[30], p[30], m[30];

int need[120], accum[120];
int ans = INT_MAX;

void MyBT(int len, int curMoney)
{
    if(len >= M)
    {
        for(int i=1; i<=100; i++)
        {
            if(accum[i] < need[i])
                return;
        }

        ans = min(ans, curMoney);
        return;
    }

    // 1. len번 에어컨 켰을 때
    for(int i=a[len]; i<=b[len]; i++)
    {
        accum[i] += p[len];
    }
    MyBT(len+1, curMoney+m[len]);
    for(int i=a[len]; i<=b[len]; i++)
    {
        accum[i] -= p[len];
    }

    // 2. len번 에어컨 안 켰을 때
    MyBT(len+1, curMoney);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("tracing.in", "r", stdin);
	// freopen("tracing.out", "w", stdout);

    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        cin >> s[i] >> t[i] >> c[i];
    }

    for(int i=0; i<M; i++)
    {
        cin >> a[i] >> b[i] >> p[i] >> m[i];
    }

    // 1. 각 방 번호 별 필요한 냉각 온도 저장
    for(int i=0; i<N; i++)
    {
        for(int j=s[i]; j<=t[i]; j++)
        {
            need[j] = c[i];
        }
    }

    // 2. 완탐
    MyBT(0, 0);
    cout << ans;

}