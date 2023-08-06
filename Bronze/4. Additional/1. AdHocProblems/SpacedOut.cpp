// http://www.usaco.org/index.php?page=viewproblem2&cpid=1088

#include "bits/stdc++.h"
using namespace std;

int N;
int score[1010][1010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("art.in", "r", stdin);
    // freopen("art.out", "w", stdout);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> score[i][j];
        }
    }

    int widthMax = 0;
    int heightMax = 0;

    for(int i=0; i<N; i++)
    {
        int lineWidthSumOdd = 0;
        int lineWidthSumEven = 0;
        int lineHeightSumOdd = 0;
        int lineHeightSumEven = 0;

        for(int j=0; j<N; j++)
        {
            if(j%2 == 1)
            {
                lineWidthSumOdd += score[i][j];
                lineHeightSumOdd += score[j][i];
            }
            else
            {
                lineWidthSumEven += score[i][j];
                lineHeightSumEven += score[j][i];
            }
        }

        widthMax += max(lineWidthSumOdd, lineWidthSumEven);
        heightMax += max(lineHeightSumOdd, lineHeightSumEven);
    }

    cout << max(widthMax, heightMax);

}