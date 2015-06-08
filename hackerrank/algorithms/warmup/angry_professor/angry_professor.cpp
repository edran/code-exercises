#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string  is_cancelled(int n, int k) {
  int temp;
  int counter = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (temp <= 0)
      counter++;
  }
  if (counter >= k)
    return "NO";
  else
    return "YES";
}

int main() {
  int k, n;
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    cin >> n >> k;
    cout << is_cancelled(n,k) << endl;
  }

  return 0;
}
