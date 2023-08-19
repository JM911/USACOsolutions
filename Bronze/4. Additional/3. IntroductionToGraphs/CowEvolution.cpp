// http://www.usaco.org/index.php?page=viewproblem2&cpid=941

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int N;
unordered_set<string> s[30];

int main()
{
    setIO("evolution");

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int K;
        cin >> K;

        for(int j=0; j<K; j++)
        {
            string tmp;
            cin >> tmp;
            s[i].insert(tmp);
        }
    }

    bool bCheck = true;

    for(int i=0; i<N; i++)
    {
        if(s[i].size() < 2)
            continue;
        
        for(auto a : s[i])
        {
            for(auto b : s[i])
            {
                if(a == b)
                    continue;

                for(int j=0; j<N; j++)
                {
                    if(j == i)
                        continue;
                    
                    if(s[j].find(a) != s[j].end() && s[j].find(b) == s[j].end())
                    {
                        for(int k = j+1; k<N; k++)
                        {
                            if(k == i)
                                continue;
                            if(s[k].find(b) != s[k].end() && s[k].find(a) == s[k].end())
                            {
                                bCheck = false;
                                break;
                            }
                        }
                    }
                    
                    if(s[j].find(b) != s[j].end() && s[j].find(a) == s[j].end())
                    {
                        for(int k = j+1; k<N; k++)
                        {
                            if(k == i)
                                continue;
                            if(s[k].find(a) != s[k].end() && s[k].find(b) == s[k].end())
                            {
                                bCheck = false;
                                break;
                            }
                        }
                    }

                    if(!bCheck)
                        break;
                }
                
                if(!bCheck)
                    break;
            }

            if(!bCheck)
                break;
        }

        if(!bCheck)
            break;
    }

    if(bCheck)
        cout << "yes";
    else
        cout << "no";
}
