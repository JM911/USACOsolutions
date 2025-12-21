// https://usaco.org/index.php?page=viewproblem2&cpid=831
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

vector<char> en1;
vector<pair<char, char>> en2;
int ans1, ans2;

void Enroll(char a)
{
  en1.push_back(a);
}

void Enroll(char a, char b) 
{
  en2.push_back({a, b});
}

bool IsEnrolled(char a)
{
  for(auto e : en1)
  {
    if(e == a)
      return true;
  }

  return false;
}

bool IsEnrolled(char a, char b)
{
  for(auto e : en2)
  {
    if(e.first == a && e.second == b)
      return true;
    
    if(e.second == a && e.first == b)
      return true;
  }

  return false;
}

int GetCharCount(char a, char b, char c)
{
  if(a==b && a==c)
    return 1;
  
  if(a==b || a==c || b==c)
    return 2;
  
  return 3;
}

pair<char, char> GetTwoChar(char a, char b, char c)
{
  if (a != b)
    return {a, b};
  if (a != c)
    return {a, c};
  
  return {b, c};
}

void Solve(char a, char b, char c)
{
  int cnt = GetCharCount(a, b, c);
  if(cnt == 1)
  {
    if(IsEnrolled(a))
    {
      return;
    }

    ++ans1;
    Enroll(a);
    return;
  }

  if(cnt == 2)
  {
    auto chars = GetTwoChar(a, b, c);
    if(IsEnrolled(chars.first, chars.second))
    {
      return;
    }

    ++ans2;
    Enroll(chars.first, chars.second);
    return;
  }
}

int main()
{
	setIO("tttt");

  en1.clear();
  en2.clear();
  ans1 = 0;
  ans2 = 0;

  string l1, l2, l3;
  cin >> l1 >> l2 >> l3;

  Solve(l1[0], l1[1], l1[2]);
  Solve(l2[0], l2[1], l2[2]);
  Solve(l3[0], l3[1], l3[2]);
  Solve(l1[0], l2[0], l3[0]);
  Solve(l1[1], l2[1], l3[1]);
  Solve(l1[2], l2[2], l3[2]);
  Solve(l1[0], l2[1], l3[2]);
  Solve(l3[0], l2[1], l1[2]);
  
  cout << ans1 << "\n" << ans2;
}