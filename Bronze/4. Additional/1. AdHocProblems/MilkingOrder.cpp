#include "bits/stdc++.h"
using namespace std;

int N, M, K;
int pos[110];
int mustOrder[110];
bool bOneInMust = false;
int oneIdxInMust = -1;
bool bOneInPos = false;
int oneIdxInPos = -1;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    cin >> N >> M >> K;
    for(int i=0; i<M; i++)
    {
        cin >> mustOrder[i];

        if(mustOrder[i] == 1)
        {
            bOneInMust = true;
            oneIdxInMust = i;
        }
    }
    for(int i=0; i<K; i++)
    {
        int cow, idx;
        cin >> cow >> idx;
        pos[idx] = cow;

        if(cow == 1)
        {
            bOneInPos = true;
            oneIdxInPos = idx;
        }
    }

    // 1. 1번 소에 미리 정해진 포지션이 있을 경우
    if(bOneInPos)
    {
        cout << oneIdxInPos;
        return 0;
    }

    // 2. 1번 소에 정해진 순서가 있을 경우
    int lastCountBeforeOne = -1;
    int lastPosIdxBeforeOne = -1;

    if(bOneInMust)
    {
        for(int i=0; i<oneIdxInMust; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(pos[j] == mustOrder[i])
                {
                    lastCountBeforeOne = i;
                    lastPosIdxBeforeOne = j;
                    continue;
                }
            }
        }

        // 2-1. 1번 소 순서보다 앞에 있는 소들이 아무도 정해진 위치가 없을 경우 => 앞에서부터 차례대로 채워나감
        if(lastCountBeforeOne < 0)
        {
            int count = 0;
            for(int i=1; i<=N; i++)
            {
                if(pos[i] == 0)
                {
                    if(mustOrder[count] == 1)
                    {
                        cout << i;
                        return 0;
                    }
                    else
                        count++;
                }
            }
        }
        else    // 2-2. 1번 소 순서보다 앞에 있으며 + 정해진 위치가 있는 소들 중 가장 뒷번호를 구해 그 뒤로 차례대로 채워나감
        {
            int count = lastCountBeforeOne + 1;
            for(int i=lastPosIdxBeforeOne+1; i<=N; i++)
            {
                if(pos[i] == 0)
                {
                    if(mustOrder[count] == 1)
                    {
                        cout << i;
                        return 0;
                    }
                    else
                        count++;
                }
            }
        }
    }

    // 3. 1번 소에 정해진 순서가 없을 경우
    int count = 0;
    for(int i=1; i<=N; i++)
    {
        if(pos[i] == 0)
        {
            int curCount = count;
            bool bCheck = true;
            for(int j=i+1; j<=N; j++)
            {
                if(pos[j] == 0 || pos[j] == mustOrder[curCount])
                {
                    curCount++;
                }
                else
                {
                    for(int k=curCount+1; k<M; k++)
                    {
                        if(mustOrder[k] == pos[j])
                        {
                            bCheck = false;
                            break;
                        }
                    }
                }

                if(!bCheck)
                    break;
            }

            if(bCheck)
            {
                cout << i; 
                return 0;
            }
            count++;
        }
        else if(pos[i] == mustOrder[count])
            count++;
    }

}