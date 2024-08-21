// https://cses.fi/problemset/task/1164/

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

struct customer {
	int idx;
	int a, b;
	int roomNum = -1;

	customer(int newIdx, int newA, int newB) 
	: idx(newIdx), a(newA), b(newB) { }
};

bool CompByIdx(const customer& A, const customer& B) {
	return A.idx < B.idx;
}

bool CompByDay(const customer& A, const customer& B) {
	if(A.a == B.a) return A.b < B.b;
	return A.a < B.a;
}

struct room {
	int num;
	int emptyDay = 1;
};

struct CompRoom {
	bool operator()(const room& A, const room& B) const {
		// if(A.emptyDay == B.emptyDay) return A.num > B.num;
		return A.emptyDay > B.emptyDay;
	}
};

int main()
{
	setIO("");

	int n;
	cin >> n;

	vector<customer> v;
	v.reserve(n+1);

	while(n--) {
		int idx = v.size();
		int a, b;
		cin >> a >> b;

		v.push_back(customer(idx, a, b));
	}
	sort(v.begin(), v.end(), CompByDay);

	priority_queue<room, vector<room>, CompRoom> pq;
	room firstRoom;
	firstRoom.num = 1;
	pq.push(firstRoom);
	
	for(auto& elem : v) {
		room newRoom;
		if(elem.a >= pq.top().emptyDay) {
			elem.roomNum = pq.top().num;
			pq.pop();
		}
		else {
			elem.roomNum = pq.size() + 1;
		}

		newRoom.num = elem.roomNum;
		newRoom.emptyDay = elem.b + 1;
		pq.push(newRoom);
	}

	cout << pq.size() << '\n';
	sort(v.begin(), v.end(), CompByIdx);
	for(auto elem : v)
		cout << elem.roomNum << ' ';
}