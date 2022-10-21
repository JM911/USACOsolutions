#include <bits/stdc++.h>
using namespace std;

int T, N;

int main()
{
    // freopen("cownomics.in", "r", stdin);
    // freopen("cownomics.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while(T--)
    {
        cin >> N;

        vector<long long> sleepTime;
        long long sum = 0;
        
        for (int i = 0; i < N; i++)
        {
            long long tmp;
            cin >> tmp;
            sleepTime.push_back(tmp);
            sum += tmp;
        }

        int num = N;
        
        while(true)
        {
            if(sum % num == 0)
            {
                long long sameNum = sum / num;
                queue<long long> q;
                for(auto a : sleepTime)
                {
                    q.push(a);
                }

                bool bCheck = true;
                long long tmpSum = 0;

                while(!q.empty())
                {
                    tmpSum += q.front();
                    q.pop();

                    if(tmpSum == sameNum)
                    {
                        tmpSum = 0;
                    }
                    else if (tmpSum > sameNum || q.empty())
                    {
                        bCheck = false;
                        break;
                    }
                }

                if(bCheck)
                {
                    break;
                }
            }

            num--;
        }

        cout << N - num << '\n';
    }
}