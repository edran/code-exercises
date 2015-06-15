#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string convert(string s) {
  string d = s.substr(s.size() - 2);
  string h = s.substr(0, 2);
  if (d == "AM" && h == "12") {
    s[0] = '0';
    s[1] = '0';
    return s.substr(0, s.size() - 2);
  }
  else if(d == "PM" && h != "12") {
    string h = s.substr(0, 2);
    stringstream ss;
    ss << (atoi(h.c_str()) + 12);
    h = ss.str();
    s[0] = h[0];
    s[1] = h[1];
    return s.substr(0, s.size() - 2);
  }
  return s.substr(0, s.size() - 2);
}

int main() {
  string s;
  cin >> s;
  cout << convert(s) << endl;
  return 0;
}
