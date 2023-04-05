#include "bits/stdc++.h"
using namespace std;

int n;
int nums[200010];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // freopen("backforth.in", "r", stdin);
	// freopen("backforth.out", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums+n);
    
    int ans = 1;
    for(int i=1; i<n; i++)
    {
        if(nums[i] != nums[i-1])
            ans++;
    }

    cout << ans;
}