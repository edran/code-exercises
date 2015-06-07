#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int op_palindrome(string s)
{
  int sum = 0;
  for (int i = 0; i < s.size()/2; i++)
  {
    sum += abs(s[i] - s[s.size() - 1 - i]);
  }
  return sum;
}

int main() {
  string word;
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    cin >> word;
    cout << op_palindrome(word) << endl;
  }
  return 0;
}
