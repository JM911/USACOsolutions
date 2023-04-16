#include "bits/stdc++.h"
using namespace std;

unordered_map<long long, long long> m;
int Q;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("angry.in", "r", stdin);
	// freopen("angry.out", "w", stdout);

    cin >> Q;
    while(Q--)
    {
        int cmd;
        cin >> cmd;

        if(cmd == 0)
        {
            long long k, v;
            cin >> k >> v;
            m[k] = v;
        }
        else
        {
            long long k;
            cin >> k;
            if(m.count(k) == 0)
                cout << 0 << '\n';
            else
                cout << m[k] << '\n';
        }
    }
}