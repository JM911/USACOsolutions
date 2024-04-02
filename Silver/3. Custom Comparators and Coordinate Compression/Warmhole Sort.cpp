// https://usaco.org/index.php?page=viewproblem2&cpid=992

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

using tiii = tuple<int, int, int>;

bool MyComp(const tiii& a, const tiii& b)
{
	return get<0>(a) > get<0>(b);
}

/* Union Find */
vector<int> myUnion;
void UnionInit()
{
	myUnion.clear();
	myUnion.resize(100010, -1);
}

int UnionFind(int x)
{
	if(myUnion[x] < 0)
		return x;
	return myUnion[x] = UnionFind(myUnion[x]);
}

void UnionMerge(int x, int y)
{
	x = UnionFind(x);
	y = UnionFind(y);

	if(x == y) return;

	if(myUnion[x] == myUnion[y])
	{
		myUnion[x] = y;
		--myUnion[y];
	}

	else if(myUnion[x] < myUnion[y])
		myUnion[y] = x;
	else
		myUnion[x] = y;
}
/* ~Union Find */

int main()
{
	setIO("wormsort");

	UnionInit();

	int N, M;
	cin >> N >> M;

	set<int> s;
	for(int i=0; i<N; ++i)
	{
		int tmp;
		cin >> tmp;
		
		if(tmp != i+1)
			s.insert(tmp);
	}

	vector<tiii> v;
	while(M--)
	{
		int a, b, w;
		cin >> a >> b >> w;
		v.push_back({w, a, b});
	}

	if(s.empty())
	{
		cout << -1;
		return 0;
	}

	sort(v.begin(), v.end(), MyComp);
	for(auto elem : v)
	{
		int a = get<1>(elem);
		int b = get<2>(elem);

		if(UnionFind(a) != UnionFind(b))
			UnionMerge(a, b);
		
		int target = *s.begin();
		int targetRoot = UnionFind(target);
		bool bConnected = true;
		for(auto e : s)
		{
			if(targetRoot != UnionFind(e))
			{
				bConnected = false;
				break;
			}
		}

		if(bConnected)
		{
			cout << get<0>(elem);
			return 0;
		}
	}
}