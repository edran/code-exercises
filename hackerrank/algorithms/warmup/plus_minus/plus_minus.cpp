#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void plus_minus(vector<int> v) {
  float pos = 0;
  float neg = 0;
  float zeros = 0;
  for (auto i = v.begin(); i != v.end(); i++)
  {
    if (*i > 0)
      pos++;
    else if(*i == 0)
      zeros++;
    else
      neg++;
  }
  cout << fixed << setprecision(3) << pos / v.size() << endl;
  cout << fixed << setprecision(3) << neg / v.size() << endl;
  cout << fixed << setprecision(3) << zeros / v.size() << endl;
  return;
}

int main() {
  vector<int> v;
  int t;
  int temp;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  plus_minus(v);
  return 0;
}
