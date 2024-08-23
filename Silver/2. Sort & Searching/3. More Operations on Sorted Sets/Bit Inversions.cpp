// https://cses.fi/problemset/task/1188

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

using pii = pair<int, int>;
constexpr int MAX_SIZE = 200'010;

int main()
{
	setIO("");

	vector<int> data;
	// map<int, pii> m; // 시작점 - {끝점, 비트}  (끝점 포함x)
	map<int, int> m; // 시작점 - 끝점 (끝점 포함x)
	multiset<int> lenSet;

	string s;
	cin >> s;

	int n = s.size();
	data.resize(n + 2);
	data[0] = 2;
	data[n+1] = 2;

	for(int i=1; i<=n; ++i)
		data[i] = (s[i-1] == '1' ? 1 : 0);

	// init
	int curData = data[1], curIdx = 1;
	int startIdx = 1;

	while(++curIdx <= n+1) {
		if(data[curIdx] != data[curIdx-1]) {
			// m.insert({startIdx, {curIdx, data[startIdx]}});
			m.insert({startIdx, curIdx});
			lenSet.insert(curIdx - startIdx);
			startIdx = curIdx;
		}
	}

	// query
	int q;
	cin >> q;

	vector<int> queries(q);
	for(auto& elem : queries)
		cin >> elem;

	for(auto x : queries) {
		// int x;
		// cin >> x;

		int prevData = data[x], curData = 1 - prevData;
		int frontData = data[x-1], backData = data[x+1];
		data[x] = curData;

		if(x == 1) {
			if(backData != curData) {	// 00 -> 10
				int nextIdx = m[1];
				int eraseLen = nextIdx - 1;
				int insertLen1 = 1;
				int insertLen2 = nextIdx - 2;

				m[1] = 2;
				m[2] = nextIdx;

				lenSet.erase(lenSet.find(eraseLen));
				lenSet.insert(insertLen1);
				lenSet.insert(insertLen2);
			}
			else {	// 10 -> 00
				int nextIdx = m[2];
				int eraseLen1 = 1;
				int eraseLen2 = nextIdx - 2;
				int insertLen = nextIdx - 1;

				m.erase(2);
				m[1] = nextIdx;

				lenSet.erase(lenSet.find(eraseLen1));
				lenSet.erase(lenSet.find(eraseLen2));
				lenSet.insert(insertLen);
			}
		}
		else if(x == n) {
			if(frontData != curData) { // ..00 -> ..01
				auto prevIter = prev(m.end());
				int prevIdx = prevIter->first;
				int eraseLen = (n+1) - prevIdx;
				int insertLen1 = n - prevIdx;
				int insertLen2 = 1;

				m[prevIdx] = n;
				m[n] = n+1;

				lenSet.erase(lenSet.find(eraseLen));
				lenSet.insert(insertLen1);
				lenSet.insert(insertLen2);
			}
			else {	// ..10 -> ..11
				auto prevIter = prev(prev(m.end()));
				int prevIdx = prevIter->first;
				int eraseLen1 = n - prevIdx;
				int eraseLen2 = 1;
				int insertLen = n+1 - prevIdx;

				m.erase(n);
				m[prevIdx] = n+1;

				lenSet.erase(lenSet.find(eraseLen1));
				lenSet.erase(lenSet.find(eraseLen2));
				lenSet.insert(insertLen);
			}
		}
		else {
			if(frontData != curData) {
				if(backData != curData) {
					auto iter = m.lower_bound(x);
					auto prevIter = prev(iter);
					int eraseLen = prevIter->second - prevIter->first;

					// m.insert({prevIter->first, x});
					// m.insert({x, x+1});
					// m.insert({x+1, prevIter->second});
					int prevFirst = prevIter->first;
					int prevSecond = prevIter->second;

					m[prevFirst] = x;
					m[x] = x+1;
					m[x+1] = prevSecond;

					lenSet.erase(lenSet.find(eraseLen));
					lenSet.insert(x - prevFirst);
					lenSet.insert(1);
					lenSet.insert(prevSecond - (x+1));
				}
				else {
					auto iter = m.lower_bound(x);
					auto prevIter = prev(iter);

					int eraseLen1 = (x+1) - prevIter->first;
					int eraseLen2 = iter->second - (x+1);
					int insertLen1 = x - prevIter->first;
					int insertLen2 = iter->second - x;

					m.erase(x+1);
					// m.insert({prevIter->first, x});
					// m.insert({x, iter->second});
					int prevFirst = prevIter->first;
					int iterSecond = iter->second;

					m[prevFirst] = x;
					m[x] = iterSecond;

					lenSet.erase(lenSet.find(eraseLen1));
					lenSet.erase(lenSet.find(eraseLen2));
					lenSet.insert(insertLen1);
					lenSet.insert(insertLen2);
				}
			}
			else {
				if(backData != curData) {
					auto iter = m.lower_bound(x);
					auto prevIter = prev(iter);

					int eraseLen1 = x - prevIter->first;
					int eraseLen2 = iter->second - x;
					int insertLen1 = x+1 - prevIter->first;
					int insertLen2  = iter->second - (x+1);

					m.erase(x);
					// m.insert({prevIter->first, x+1});
					// m.insert({x+1, iter->second});
					int prevFirst = prevIter->first;
					int iterSecond = iter->second;

					m[prevFirst] = x+1;
					m[x+1] = iterSecond;

					lenSet.erase(lenSet.find(eraseLen1));
					lenSet.erase(lenSet.find(eraseLen2));
					lenSet.insert(insertLen1);
					lenSet.insert(insertLen2);
				}
				else {
					m.erase(x);
					auto iter = m.lower_bound(x);
					auto prevIter = prev(iter);

					int eraseLen1 = 1;
					int eraseLen2 = x - prevIter->first;
					int eraseLen3 = iter->second - (x+1);
					int insertLen = iter->second - prevIter->first;

					// m.insert({prevIter->first, iter->second});
					int prevFirst = prevIter->first;
					int iterSecond = iter->second;

					m[prevFirst] = iterSecond;
					m.erase(iter);

					lenSet.erase(lenSet.find(eraseLen1));
					lenSet.erase(lenSet.find(eraseLen2));
					lenSet.erase(lenSet.find(eraseLen3));
					lenSet.insert(insertLen);
				}
			}
		}

		cout << *(prev(lenSet.end())) << ' ';
	}
}