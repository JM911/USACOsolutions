// http://www.usaco.org/index.php?page=viewproblem2&cpid=833

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
string A, B;
unordered_map<string, vector<string>> PD;
unordered_set<string> allParents;

pair<int, int> GetStepToAB(string targetParent)
{
    //int step = 0;
    int aStep = INT_MAX;
    int bStep = INT_MAX;
    unordered_map<string, int> visitedMap;

    queue<string> q;
    q.push(targetParent);
    visitedMap.insert({targetParent, 0});

    while(!q.empty())
    {
        string curName = q.front();
        q.pop();
        
        if(curName == A)
        {
            aStep = min(aStep, visitedMap[curName]);
        }
        if(curName == B)
        {
            bStep = min(bStep, visitedMap[curName]);
        }

        for(auto child : PD[curName])
        {
            if(visitedMap.find(child) == visitedMap.end())
            {
                q.push(child);
                visitedMap.insert({child, visitedMap[curName] + 1});
            }
        }
    }

    pair<int, int> ret{-1, -1};
    if(aStep < INT_MAX) ret.first = aStep;
    if(bStep < INT_MAX) ret.second = bStep;

    return ret;
}

int main()
{
    setIO("family");

    cin >> N >> A >> B;
    for(int i=0; i<N; i++)
    {
        string X, Y;
        cin >> X >> Y;
        
        if(PD.find(X) == PD.end())
        {
            vector<string> v;
            PD.insert({X, v});
        }

        PD[X].push_back(Y);
        allParents.insert(X);
    }

    string shortestCommonParent{};
    pair<int, int> shortestStep{INT_MAX, INT_MAX};

    for(auto parent : allParents)
    {
        auto result = GetStepToAB(parent);
        if(result.first == -1 || result.second == -1)
        {
            continue;
        }

        if(result.first < shortestStep.first)
        {
            shortestCommonParent = parent;
            shortestStep = result;
        }
    }

    string relationship{};
    bool bReverse = false;  // A가 더 상위면 true

    if(shortestCommonParent == "")
    {
        relationship = "NOT RELATED";
    }

    else if(shortestStep.first == 0)
    {
        bReverse = true;
        int curStep = shortestStep.second;
        while(curStep--)
        {
            if(relationship == "")
                relationship = "mother";
            else if(relationship == "mother")
                relationship = "grand-mother";
            else
                relationship = "great-" + relationship;
        }
    }

    else if(shortestStep.first == 1)
    {
        bReverse = true;
        int curStep = shortestStep.second;
        if(shortestStep.second == 0)
        {
            bReverse = false;
            relationship = "mother";
        }
        
        while(curStep--)
        {
            if(relationship == "")
            {
                bReverse = false;
                relationship = "SIBLINGS";
            }
            else if(relationship == "SIBLINGS")
            {
                bReverse = true;
                relationship = "aunt";
            }
            else
                relationship = "great-" + relationship;
        }
    }

    else if(shortestStep.first >= 2)
    {
        if(shortestStep.second == 0)
        {
            bReverse = false;
            relationship = "grand-mother";
        }
        else if(shortestStep.second == 1)
        {
            bReverse =false;
            int curStep = shortestStep.first - 1;
            while(curStep--)
            {
                if(relationship == "")
                    relationship = "aunt";
                else
                    relationship = "great-" + relationship;
            }
        }
        else
            relationship = "COUSINS";
    }

    string firstName = bReverse ? A : B;
    string secondName = bReverse ? B : A;

    if(relationship == "NOT RELATED" || relationship == "SIBLINGS" || relationship == "COUSINS")
        cout << relationship;
    else
        cout << firstName << " is the " << relationship << " of " << secondName;
}
