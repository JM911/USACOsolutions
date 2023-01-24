#include "bits/stdc++.h"
using namespace std;

string s;

bool my_next_permutation(vector<char>& targetVec)
{
    /*int len = targetVec.size();
    if(len > 2)
    {
        vector<char> subVec;
        char firstElem = targetVec[0];

        for(int i=1; i<len; i++)
        {
            subVec.push_back(targetVec[i]);
        }

        bool bCheck = my_next_permutation(subVec);
        if(bCheck)
        {
            targetVec.clear();
            targetVec.push_back(firstElem);
            for(auto a : subVec)
            {
                targetVec.push_back(a);
            }

            return true;
        }
        else
        {
            for(int i=len-1; i>0; i--)
            {
                if(targetVec[i] > firstElem)
                {
                    targetVec[0] = targetVec[i];
                    targetVec[i] = firstElem;
                    //sort(targetVec.begin()+1, targetVec.end());
                    reverse(targetVec.begin()+1, targetVec.end());

                    return true;
                }
            }
            return false;
        }
    }
    else if(len == 2)
    {
        if(targetVec[0] < targetVec[1])
        {
            char tmp = targetVec[0];
            targetVec[0] = targetVec[1];
            targetVec[1] = tmp;

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }*/

    int len = targetVec.size();
    if(len < 2)
        return false;
    
    for(int i=len-1; i>0; i--)
    {
        if(targetVec[i-1] < targetVec[i])   // 일반화 할 경우 compare 함수
        {
            int swapTargetIndex = len-1;
            while(targetVec[i-1] >= targetVec[swapTargetIndex])
            {
                swapTargetIndex--;
            }

            char tmp = targetVec[i-1];
            targetVec[i-1] = targetVec[swapTargetIndex];
            targetVec[swapTargetIndex] = tmp;

            reverse(targetVec.begin()+i, targetVec.end());
            return true;
        }
    }

    return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("tracing.in", "r", stdin);
	// freopen("tracing.out", "w", stdout);

    cin >> s;

    vector<char> alp;
    for(auto a : s)
    {
        alp.push_back(a);
    }

    sort(alp.begin(), alp.end());

    string newS;
    vector<string> vecNewS;

    do
    {
        newS = "";
        for(auto a : alp)
        {
            newS.push_back(a);
        }
        vecNewS.push_back(newS);
    } while (my_next_permutation(alp)); //(next_permutation(alp.begin(), alp.end()));
    
    cout << vecNewS.size() << '\n';
    for(auto a : vecNewS)
    {
        cout << a << '\n';
    }
}