// https://cses.fi/problemset/task/2431/

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

int q;
long long k;

int main()
{
    setIO("");

    cin >> q;
    while(q--)
    {
        cin >> k;

        long long tmpK = k;
        long long count = 1;
        long long tenCount = 1;

        while(tmpK > 0)
        {
            long long tmp = count * (9 * tenCount);
            if(tmpK <= tmp)
                break;
            
            tmpK -= tmp;
            count++;
            tenCount *= 10;
        }

        long long a = (tmpK - 1) / count;
        long long b = (tmpK - 1) % count;

        long long targetNum = tenCount + a;
        
        long long targetIdx = count - 1 - b;
        long long tmpTen = 10;
        for(long long i=0; i<targetIdx; i++)
        {
            tmpTen *= 10;
        }

        targetNum %= tmpTen;
        targetNum /= (tmpTen / 10);

        cout << targetNum << '\n';
    }
}
