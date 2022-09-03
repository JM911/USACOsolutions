#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_set<int> spotty;
vector<vector<char>> spotGen;
vector<vector<char>> noSpotGen;
int ans;

int MyHash(char a, char b, char c)
{
    int ia = a - 'A';
    int ib = b - 'A';
    int ic = c - 'A';

    return ia * 30 * 30 + ib * 30 + ic;
}

int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;

        spotGen.push_back(vector<char>());

        for(auto a : tmp)
        {
            spotGen[i].push_back(a);
        }
    }

    for(int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;

        noSpotGen.push_back(vector<char>());

        for(auto a : tmp)
        {
            noSpotGen[i].push_back(a);
        }
    }


    for (int i = 0; i < M - 2; i++)
    {
        for (int j = i + 1; j < M - 1; j++)
        {
            for (int k = j + 1; k < M; k++)
            {
                spotty.clear();
                for (int l = 0; l < N; l++)
                {
                    spotty.insert(MyHash(spotGen[l][i], spotGen[l][j], spotGen[l][k]));
                }

                bool bCheck = true;

                for (int l = 0; l < N; l++)
                {
                    if(spotty.find(MyHash(noSpotGen[l][i], noSpotGen[l][j], noSpotGen[l][k])) != spotty.end())
                    {
                        bCheck = false;
                        break;
                    }
                }

                if(bCheck)
                    ans++;
            }
        }
    }

    cout << ans;
}