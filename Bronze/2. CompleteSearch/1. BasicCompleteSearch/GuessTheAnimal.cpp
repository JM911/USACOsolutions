#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<string, unordered_set<string>> animals;
int ans;

int main()
{
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name;
        unordered_set<string> characs;
        int K;
        cin >> name >> K;
        
        while(K--)
        {
            string tmp;
            cin >> tmp;
            characs.insert(tmp);
        }

        animals[name] = characs;
    }   

    for(auto a : animals)
    {
        for(auto b : animals)
        {
            if(a.first == b.first)
                continue;

            int commonNum = 0;

            for(auto c : a.second)
            {
                if(b.second.find(c) != b.second.end())
                {
                    commonNum++;
                }
            }

            if(a.second.size() > commonNum || b.second.size() > commonNum)
                commonNum++;

            ans = max(ans, commonNum);
        }
    }

    cout << ans;
}