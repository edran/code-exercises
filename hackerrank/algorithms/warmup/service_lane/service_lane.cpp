#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int length, t;
  cin >> length >> t;
  vector<int> width;
  int temp;
  for (int i = 0; i < length; i++) {
    cin >> temp;
    width.push_back(temp);
  }
  int n1, n2;

  for (int i = 0; i < t; i++) {
    cin >> n1 >> n2;
    // cout << width[n1] << " " << width[n2] << endl;
    cout << *min_element(width.begin() + n1, width.begin() + n2 + 1) << endl;
  }

  return 0;
}
