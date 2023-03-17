#include "bits/stdc++.h"
using namespace std;

int MyCalc(int a, int b, int op)
{
    switch(op)
    {
    case 0:
        return a + b;
        break;
    case 1:
        return a - b;
        break;
    case 2:
        return a * b;
        break;
    case 3:
        if(b != 0 && a % b == 0)  return a / b ;
        else return INT_MAX;
        break;
    }

    return INT_MAX;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("backforth.in", "r", stdin);
	// freopen("backforth.out", "w", stdout);

    int N;
    cin >> N;

    while(N--)
    {
        int card[4];
        for(int i=0; i<4; i++)
        {
            cin >> card[i];
        }

        int index[4] = {0, 1, 2, 3};
        int ans = INT_MIN;

        do
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    for(int k=0; k<4; k++)
                    {
                        bool bCheck_main = true;
                        int mainResult_1 = MyCalc(card[index[0]], card[index[1]], i);
                        if(mainResult_1 == INT_MAX) bCheck_main = false;
                        int mainResult_2 = MyCalc(mainResult_1, card[index[2]], j);
                        if(mainResult_2 == INT_MAX) bCheck_main = false;
                        int mainResult_3 = MyCalc(mainResult_2, card[index[3]], k);
                        if(mainResult_3 == INT_MAX) bCheck_main = false;

                        if(bCheck_main && mainResult_3 <= 24) ans = max(ans, mainResult_3);

                        bool bCheck_sub = true;
                        int subResult_1 = MyCalc(card[index[0]], card[index[1]], i);
                        if(subResult_1 == INT_MAX) bCheck_sub = false;
                        int subResult_2 = MyCalc(card[index[2]], card[index[3]], j);
                        if(subResult_2 == INT_MAX) bCheck_sub = false;
                        int subResult_3 = MyCalc(subResult_1, subResult_2, k);
                        if(subResult_3 == INT_MAX) bCheck_sub = false;

                        if(bCheck_sub && subResult_3 <= 24) ans = max(ans, subResult_3);
                    }
                }
            }
        } while (next_permutation(index, index+4));

        cout << ans << '\n';
    }
}