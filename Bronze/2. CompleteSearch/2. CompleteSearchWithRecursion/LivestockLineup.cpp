#include "bits/stdc++.h"
using namespace std;

string Cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
int CowNums[8] = {0, 1, 2, 3, 4, 5, 6, 7};
vector<pair<int, int>> constraints;

int GetCowIndex(const string& cowName)
{
    for(int i=0; i<8; i++)
    {
        if(Cows[i] == cowName)
            return i;
    }

    return -1;
}

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);

    sort(Cows, Cows+8);

    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string firstName, dummy, secondName;
        cin >> firstName >> dummy >> dummy >> dummy >> dummy >> secondName;

        constraints.push_back({GetCowIndex(firstName), GetCowIndex(secondName)});
    }

    do
    {
        bool bCheck = true;
        for(auto constraint : constraints)
        {
            for(int i=0; i<8; i++)
            {
                if(CowNums[i] == constraint.first)
                {
                    if((i-1 >= 0 && CowNums[i-1] == constraint.second) || (i+1 < 8 && CowNums[i+1] == constraint.second))
                        continue;
                    bCheck = false;
                }
            }
        }

        if(bCheck)
        {
            break;
        }
    } while(next_permutation(CowNums, CowNums+8));

    for(int i=0; i<8; i++)
    {
        cout << Cows[CowNums[i]] << '\n';
    }
}