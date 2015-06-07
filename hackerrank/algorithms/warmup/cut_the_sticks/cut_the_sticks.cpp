#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void cuts(vector<int> v) {
  int d;
  int n = v.size();
  vector<int> temp;
  while(n != 0)
  {
    cout << n << endl;
    d = *min_element(v.begin(), v.end());
    for (auto i = v.begin(); i != v.end(); i++)
    {
      *i -= d;
      if (*i > 0)
        temp.push_back(*i);
    }
    n = temp.size();
    v = temp;
    temp.clear();
  }
  return;
}

int main() {
  int t;
  cin >> t;
  vector<int> v;
  int temp;
  for (int i=0; i<t; i++) {
    cin >> temp;
    v.push_back(temp);
  }
  cuts(v);
  return 0;
}
