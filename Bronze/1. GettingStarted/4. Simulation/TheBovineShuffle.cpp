// https://usaco.org/index.php?page=viewproblem2&cpid=760
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

int main()
{
	setIO("shuffle");
	// setIO("");

	int N;
  cin >> N;

  vector<int> a(N+1, 0);
  for(int i=1; i<=N; ++i)
    cin >> a[i];
  
  vector<int> id(N+1, 0);
  for(int i=1; i<=N; ++i)
    cin >> id[i];
  
  for(int i=1; i<=N; ++i)
    cout << id[a[a[a[i]]]] << "\n";
}