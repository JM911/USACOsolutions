#include "bits/stdc++.h"
using namespace std;

int n;
int w[110];

int CalcAns(const vector<int>& v)
{
    int l = v.size();
    int sum = 0;
    for(int i=0; i<l/2; i++)
    {
        sum += abs(v[i*2] - v[i*2 + 1]);
    }

    return sum;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("backforth.in", "r", stdin);
	// freopen("backforth.out", "w", stdout);

    cin >> n;
    for(int i=0; i<2*n; i++)
    {
        cin >> w[i];
    }

    sort(w, w+2*n);
    vector<bool> sign(2*n);
    for(int i=0; i<2*n; i++)
    {
        sign[i] = true;
    }
    sign[0] = false;
    sign[1] = false;

    int ans = INT_MAX;
    do
    {
        vector<int> tmpVec;
        for(int i=0; i<2*n; i++)
        {
            if(sign[i])
                tmpVec.push_back(w[i]);
        }
        ans = min(ans, CalcAns(tmpVec));
    } while (next_permutation(sign.begin(), sign.end()));
    
    cout << ans;

}