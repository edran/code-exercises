#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int feast(int n, int c, int m) {
  int count = n / c;
  int wrapper = count;
  while (wrapper >= m) {
    int bonus = wrapper / m;
    count += bonus;
    wrapper = wrapper - bonus * (m - 1);
  }
  return count;
}

int main() {
  int num1, num2, num3;
  int out;
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    cin >> num1 >> num2 >> num3;
    out = feast(num1, num2, num3);
    cout << out << endl;
  }

  return 0;
}
