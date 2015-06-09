#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long halloween(int k) {
  long out;
  if (k % 2 == 0)
  {
    out = k / 2;
    out = out*out;
  }
  else
  {
    out = k / 2;
    out = out * (out + 1);
  }
  return out;
}

int main() {
  long long num1;
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    cin >> num1;
    cout << halloween(num1) << endl;
  }

  return 0;
}
