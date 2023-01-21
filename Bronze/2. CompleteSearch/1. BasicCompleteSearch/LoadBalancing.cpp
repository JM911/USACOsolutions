#include "bits/stdc++.h"
using namespace std;

int N, B;
int x[105], y[105];

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

    cin >> N >> B;
    set<int> setX, setY;

    for(int i=0; i<N; i++)
    {
        cin >> x[i] >> y[i];
        setX.insert(x[i]);
        setY.insert(y[i]);
    }

    int a, b;
    int M = INT_MAX;
    for(auto p : setX)
    {
        a = p + 1;
        for(auto q : setY)
        {
            b = q + 1;
            int part_1 = 0;
            int part_2 = 0;
            int part_3 = 0;
            int part_4 = 0;
            for(int i=0; i<N; i++)
            {
                if(x[i] < a && y[i] < b)    part_1++;
                if(x[i] < a && y[i] > b)    part_2++;
                if(x[i] > a && y[i] < b)    part_3++;
                if(x[i] > a && y[i] > b)    part_4++;
            }

            M = min(M, max(max(part_1, part_2), max(part_3, part_4)));
        }
    }

    cout << M;
    
}