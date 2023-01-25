#include "bits/stdc++.h"
using namespace std;

bool bBoard[10][10];
int ans;
string s;

bool FloodFillTest()
{
    int testBoard[10][10];
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            testBoard[i][j] = bBoard[i][j] == true ? 1 : 0;
        }
    }
    
    queue<pair<int, int>> q;
    testBoard[6][0] = 2;
    q.push({6, 0});

    // testBoard[6][0] = 1;
    // if(testBoard[5][0] == 0)
    // {
    //     testBoard[5][0] = 2;
    //     q.push({5, 0});
    // }
    // else if(testBoard[6][1] == 0)
    // {
    //     testBoard[6][1] = 2;
    //     q.push({6, 1});
    // }
    // else
    //     return false;

    while(!q.empty())
    {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        if(curRow+1 <= 6 && testBoard[curRow+1][curCol] == 0)
        {
            testBoard[curRow+1][curCol] = 2;
            q.push({curRow+1, curCol});
        }
        if(curRow-1 >= 0 && testBoard[curRow-1][curCol] == 0)
        {
            testBoard[curRow-1][curCol] = 2;
            q.push({curRow-1, curCol});
        }
        if(curCol+1 <= 6 && testBoard[curRow][curCol+1] == 0)
        {
            testBoard[curRow][curCol+1] = 2;
            q.push({curRow, curCol+1});
        }
        if(curCol-1 >= 0 && testBoard[curRow][curCol-1] == 0)
        {
            testBoard[curRow][curCol-1] = 2;
            q.push({curRow, curCol-1});
        }
    }
    
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            if(testBoard[i][j] == 0)
                return false;
        }
    }

    return true;
}

bool SimpleTest(int targetRow, int targetCol)
{
    // 막혀있으면 true, 갈 수 있으면 false
    bool bLeft = ((targetCol - 1 < 0) || (bBoard[targetRow][targetCol-1] == true));
    bool bRight = ((targetCol + 1 > 6) || (bBoard[targetRow][targetCol+1] == true));
    bool bUp = ((targetRow - 1 < 0) || (bBoard[targetRow-1][targetCol] == true));
    bool bDown = ((targetRow + 1 > 6) || (bBoard[targetRow+1][targetCol] == true));

    // 양분되면 false 반환, 아니면 true 반환
    if(bLeft == true && bRight == true && bUp == false && bDown == false)
        return false;
    if(bLeft == false && bRight == false && bUp == true && bDown == true)
        return false;
    return true;
}

void MyBT(int len, int lastRow, int lastCol)
{
    if(len > 48)
        return;

    // 마지막
    if(len == 48)
    {
        if(lastRow == 6 && lastCol == 0)
            ans++;
        return;
    }

    // 마지막이 아닌데 목표 칸에 닿으면 아웃
    if(bBoard[lastRow][lastCol] == true || (lastRow == 6 && lastCol == 0))
        return;

    // 최적화용 테스트
    if(!SimpleTest(lastRow, lastCol))
    {
        return;
    }
    
    bBoard[lastRow][lastCol] = true;
    
    // 1. 인풋에서 미리 정해준 방향이 있는지 확인
    char nextOrder = s[len];
    if(nextOrder != '?')
    {
        switch (nextOrder)
        {
        case 'D':
            if(lastRow + 1 <= 6)
                MyBT(len+1, lastRow+1, lastCol);
            break;
        case 'U':
            if(lastRow - 1 >= 0)
                MyBT(len+1, lastRow-1, lastCol);
            break;
        case 'L':
            if(lastCol - 1 >= 0)
                MyBT(len+1, lastRow, lastCol-1);
            break;
        case 'R':
            if(lastCol + 1 <= 6)
                MyBT(len+1, lastRow, lastCol+1);
            break;
        }
    }
    else
    {
        if(lastRow + 1 <= 6)
            MyBT(len+1, lastRow+1, lastCol);
        if(lastRow - 1 >= 0)
            MyBT(len+1, lastRow-1, lastCol);
        if(lastCol - 1 >= 0)
            MyBT(len+1, lastRow, lastCol-1);
        if(lastCol + 1 <= 6)
            MyBT(len+1, lastRow, lastCol+1);
    }

    bBoard[lastRow][lastCol] = false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("tracing.in", "r", stdin);
	// freopen("tracing.out", "w", stdout);

    cin >> s;
    MyBT(0, 0, 0);

    cout << ans;

}