#include "bits/stdc++.h"
using namespace std;

int N, T;
bool c[110];
map<int, vector<pair<int, int>>> m;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);

    cin >> N >> T;

    string s;
    cin >> s;
    for(int i=0; i<N; i++)
    {
        c[i+1] = s[i]=='1';
    }

    for(int i=0; i<T; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;
        m[t].push_back({x, y});
    }

    bool ans[110];
    fill(ans, ans+105, false);

    int minK = 300;
    int maxK = 0;

    for(int i=1; i<=N; i++)
    {
        // i가 patient zero 라고 가정
        if(c[i] == false)
            continue;

        for(int k=0; k<=250; k++)
        {
            bool state[110];
            fill(state, state + 101, false);
            state[i] = true;

            int remain[110];
            fill(remain, remain + N, 0);
            remain[i] = k;

            for(int j=1; j<=250; j++)
            {
                auto a = m[j];
                for(auto b : a)
                {
                    if(state[b.first] == state[b.second])
                    {
                        if(state[b.first] == true)
                        {
                            remain[b.first]--;
                            remain[b.second]--;
                        }
                        continue;
                    }
                    
                    int positiveNum, negativeNum;
                    if(state[b.first] == true)
                    {
                        positiveNum = b.first;
                        negativeNum = b.second;
                    }
                    else
                    {
                        positiveNum = b.second;
                        negativeNum = b.first;
                    }

                    if(remain[positiveNum] <= 0)
                        continue;
                    
                    remain[positiveNum]--;
                    state[negativeNum] = true;
                    remain[negativeNum] = k;
                }
            }

            bool bCheck = true;
            for(int j=1; j<=N; j++)
            {
                if(state[j] != c[j])
                {
                    bCheck = false;
                    break;
                }
            }

            if(bCheck)
            {
                ans[i] = true;
                minK = min(minK, k);
                maxK = max(maxK, k);
            }

        }
    }

    int ansNum = 0;
    for(int i=1; i<=N; i++)
    {
        if(ans[i])
            ansNum++;
    }

    cout << ansNum << ' ' << minK << ' ';
    if(maxK >= 250)
        cout << "Infinity";
    else
        cout << maxK;
    
}