#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int calc_diagonal(vector< vector<int> > v) {
  int first = 0;
  int second = 0;
  for (size_t i = 0; i < v.size(); i++)
  {
    first += v[i][i];
    second += v[v.size() - i - 1][i];
  }
  return abs(first - second);
}

int main() {
  int t;
  cin >> t;
  vector< vector<int> > v;
  for (int i=0; i<t; i++) {
    vector<int> temp;
    int temp_i;
    for (int k = 0; k < t; k++) {
      cin >> temp_i;
      temp.push_back(temp_i);
    }
    v.push_back(temp);
  }
  cout << calc_diagonal(v) << endl;
  return 0;
}
