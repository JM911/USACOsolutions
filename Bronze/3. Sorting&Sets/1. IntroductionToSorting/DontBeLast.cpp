#include "bits/stdc++.h"
using namespace std;

int N;
unordered_map<string, int> m;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);

    m.insert({"Bessie", 0});
    m.insert({"Elsie", 0});
    m.insert({"Daisy", 0});
    m.insert({"Gertie", 0});
    m.insert({"Annabelle", 0});
    m.insert({"Maggie", 0});
    m.insert({"Henrietta", 0});

    cin >> N;
    while(N--)
    {
        string name;
        int milk;

        cin >> name >> milk;
        m[name] += milk;
    }

    multimap<int, string> m2;

    for(auto a : m)
    {
        m2.insert({a.second, a.first});
    }

    int minMilk = m2.begin()->first;
    int ansMilk = 0;
    string ansName = "Tie";
    bool bCheck = false;

    for(auto a : m2)
    {
        if(minMilk == a.first)
            continue;
        else if(!bCheck)
        {
            ansMilk = a.first;
            ansName = a.second;
            bCheck = true;
        }
        else
        {
            if(ansMilk == a.first)
                ansName = "Tie";
            break;
        }
    }

    cout << ansName;
}