#include <bits/stdc++.h>
using namespace std;

int N;
char dir[55];
int xpos[55];
int ypos[55];
int ans[55];
bool bStop[55];

void Progress(int n)
{
    for (int i = 0; i < N; i++)
    {
        if(bStop[i])
            continue;
        
        switch(dir[i])
        {
        case 'N':
            ypos[i] += n;
            ans[i] += n;
            break;
        case 'E':
            xpos[i] += n;
            ans[i] += n;
            break;
        }
    }
}

long long myHash(int x, int y)
{
    long long lx = x;
    long long ly = y;
    return lx * 1000000010 + ly;
}

int main()
{
    // freopen("cbarn.in", "r", stdin);
    // freopen("cbarn.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //long long bil = 1000000001;
    //fill(ans, ans + 50, INT_MAX);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> dir[i] >> xpos[i] >> ypos[i];
    }

    set<int> xcand;
    set<int> ycand;

    for (int i = 0; i < N; i++)
    {
        if(dir[i] == 'N')
        {
            xcand.insert(xpos[i]);
        }
        else
        {
            ycand.insert(ypos[i]);
        }
    }

    queue<int> xcandq[55];
    queue<int> ycandq[55];

    for (int i = 0; i < N; i++)
    {
        for (auto iter = xcand.begin(); iter != xcand.end(); ++iter)
        {
            xcandq[i].push(*iter);
        }
        for (auto iter = ycand.begin(); iter != ycand.end(); ++iter)
        {
            ycandq[i].push(*iter);
        }
    }

    unordered_set<long long> us_1;

    while(true)
    {
        int nextStep = INT_MAX;

        for (int i = 0; i < N; i++)
        {
            if(bStop[i])
                continue;

            if(dir[i] == 'N')
            {
                while(!ycandq[i].empty() && ycandq[i].front() <= ypos[i])
                {
                    ycandq[i].pop();
                }

                if(ycandq[i].empty())
                    continue;

                nextStep = min(nextStep, ycandq[i].front() - ypos[i]);
            }
            else
            {
                while(!xcandq[i].empty() && xcandq[i].front() <= xpos[i])
                {
                    xcandq[i].pop();
                }

                if(xcandq[i].empty())
                    continue;

                nextStep = min(nextStep, xcandq[i].front() - xpos[i]);
            }
        }

        if(nextStep == INT_MAX)
            break;

        Progress(nextStep);

        unordered_set<long long> us_2;

        for (int i = 0; i < N; i++)
        {
            if(bStop[i])
                continue;

            if(dir[i] == 'N' && ypos[i] == ycandq[i].front())
            {
                if(us_1.find(myHash(xpos[i], ypos[i])) == us_1.end())
                {
                    us_2.insert(myHash(xpos[i], ypos[i]));
                }
                else
                {
                    bStop[i] = true;
                }
            }
            else if(dir[i] == 'E' && xpos[i] == xcandq[i].front())
            {
                if(us_1.find(myHash(xpos[i], ypos[i])) == us_1.end())
                {
                    us_2.insert(myHash(xpos[i], ypos[i]));
                }
                else
                {
                    bStop[i] = true;
                }
            }
        }

        for(auto a : us_2)
        {
            us_1.insert(a);
        }
    }

    for (int i = 0; i < N; i++)
    {
        if(!bStop[i])
            cout << "Infinity" << '\n';
        else
            cout << ans[i] << '\n';
    }
}