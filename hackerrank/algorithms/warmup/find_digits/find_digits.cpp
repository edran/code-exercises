#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int find_digits(int n) {
  stringstream ss;
  ss << n;
  string digits = ss.str();
  int count = 0;
  for (auto i = digits.begin(); i != digits.end(); i++)
  {
    if (*i == '0')
      continue;
    if (n % (*i - '0') == 0)
      count++;
  }
  return count;
}

int main() {
  int n;
  int t;
  cin >> t;
  for (int i=0; i<t; i++) {
    cin >> n;
    cout << find_digits(n) << endl;
  }

  return 0;
}
