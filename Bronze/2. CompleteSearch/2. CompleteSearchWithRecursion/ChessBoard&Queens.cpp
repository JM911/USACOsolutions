#include "bits/stdc++.h"
using namespace std;

int iBoard[10][10]; // 0: 빈 칸, 1: 퀸, 2: 배치 불가
int ans;

bool CanPlace(int row, int col)
{
    if(iBoard[row][col] != 0)
        return false;

    for(int i=0; i<row; i++)
    {
        // 1. 상하 체크
        if(iBoard[i][col] == 1)
            return false;
        
        // 2. 대각선 체크
        int diff = row - i;
        if(col - diff >= 0 && iBoard[i][col-diff] == 1)
            return false;
        if(col + diff < 8 && iBoard[i][col+diff] == 1)
            return false;
    }

    return true;
}

void MyBT(int len)
{
    if(len == 8)
    {
        ans++;
        return;
    }

    for(int i=0; i<8; i++)
    {
        if(CanPlace(len, i))
        {
            iBoard[len][i] = 1;
            MyBT(len+1);
            iBoard[len][i] = 0;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("tracing.in", "r", stdin);
	// freopen("tracing.out", "w", stdout);

    for(int i=0; i<8; i++)
    {
        string tmpStr;
        cin >> tmpStr;
        
        for(int j=0; j<8; j++)
        {
            iBoard[i][j] = tmpStr[j] == '.' ? 0 : 2;
        }
    }

    MyBT(0);
    cout << ans;

}