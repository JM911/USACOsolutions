// https://codeforces.com/problemset/problem/358/C

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

int n;
vector<int> v;
vector<int> vTemp;

int main()
{
    setIO("");

    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;

        if(a == 0)
        {
            if(v.size() == 0)
            {
                cout << 0 << '\n';
            }
            else if(v.size() == 1)
            {
                cout << "pushStack" << '\n';
                cout << "1 popStack" << '\n';
            }
            else if(v.size() == 2)
            {
                cout << "pushStack" << '\n';
                cout << "pushQueue" << '\n';
                cout << "2 popStack popQueue" << '\n';
            }
            else
            {
                // 1. 가장 큰 수 3개와 해당 수의 인덱스 구하기 (순서 상관X)
                int maxIdx[3];
                for(int i=0; i<3; i++)
                {
                    int curMax = 0;
                    int curMaxIdx = -1;
                    for(int j=0; j<vTemp.size(); j++)
                    {
                        if(vTemp[j] > curMax)
                        {
                            curMax = vTemp[j];
                            curMaxIdx = j;
                        }
                    }
                    vTemp[curMaxIdx] = 0;
                    maxIdx[i] = curMaxIdx;
                }

                // 2. for 문 돌려서 가장 큰 3개 수 인덱스에는 각각 pushStack, pushQueue, pushFront 출력 / 나머지는 pushBack 출력
                for(int i=0; i<v.size(); i++)
                {
                    if(i == maxIdx[0])
                    {
                        cout << "pushStack" << '\n';
                    }
                    else if(i == maxIdx[1])
                    {
                        cout << "pushQueue" << '\n';
                    }
                    else if(i == maxIdx[2])
                    {
                        cout << "pushFront" << '\n';
                    }
                    else
                    {
                        cout << "pushBack" << '\n';
                    }
                }

                // 3. 마지막에 3 popStack popQueue popFront 출력
                cout << "3 popStack popQueue popFront" << '\n';
            }

            v.clear();
            vTemp.clear();
        }
        else
        {
            v.push_back(a);
            vTemp.push_back(a);
        }
    }

    // 혹시라도 마지막에 0으로 끝나지 않을 경우를 위해 처리?
    while(!v.empty())
    {
        cout << "pushBack" << '\n';
        v.pop_back();
    }
}
