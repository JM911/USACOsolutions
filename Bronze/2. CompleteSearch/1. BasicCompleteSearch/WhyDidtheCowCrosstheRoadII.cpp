#include "bits/stdc++.h"
using namespace std;

int main()
{
    // cin.tie(nullptr);
    // ios_base::sync_with_stdio(false);

    freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

    string cows;
    int ans = 0;

    cin >> cows;

    for(int i = 0; i < 52; i++)
    {
        bool tmp[26];
        fill(tmp, tmp+26, false);

        for(int j = (i + 1) % 52; j != i-1;)
        {
            if(cows[i] == cows[j])
                break;
            
            tmp[cows[j] - 'A'] = !tmp[cows[j] - 'A'];

            j++;
            j %= 52;
        }

        for(int j = 0; j < 26; j++)
        {
            if(tmp[j] == true)
                ans++;
        }
    }

    ans /= 4;
    cout << ans;
}