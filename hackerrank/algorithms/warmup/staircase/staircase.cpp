#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void draw_staircase(int t) {
  for (int i = 1; i <= t; i++)
  {
    cout << string(t-i, ' ');
    cout << string(i, '#') << endl;
  }
  return;
}

int main() {
  int t;
  cin >> t;
  draw_staircase(t);
  return 0;
}
