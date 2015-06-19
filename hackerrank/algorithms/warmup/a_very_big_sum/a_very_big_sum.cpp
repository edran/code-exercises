#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solveMeSecond(int a, int b) {
  return a+b;
}

int main() {
  long num;
  long sum = 0;
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    cin >> num;
    sum += num;
  }
  cout << sum << endl;
  return 0;
}
