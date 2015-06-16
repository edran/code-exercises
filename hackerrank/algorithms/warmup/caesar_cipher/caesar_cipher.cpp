#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

string cipher(string s, int k) {
  for (auto i = s.begin(); i != s.end(); i++) {
    char c;
    if (!isalpha(*i))
      continue;
    if (isupper(*i)) {
      c = *i - 'A';
      c = (c + k) % 26;
      c += 'A';
    }
    else {
      c = *i - 'a';
      c = (c + k) % 26;
      c += 'a';
    }
    *i = c;
  }
  return s;
}

int main() {
  int t;
  cin >> t;
  string s;
  cin >> s;
  int k;
  cin >> k;
  cout << cipher(s, k) << endl;
  return 0;
}
