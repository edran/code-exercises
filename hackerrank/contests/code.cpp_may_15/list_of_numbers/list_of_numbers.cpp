#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<string> split_by_space(string s) {
  string buf; // Have a buffer string
  stringstream ss(s); // Insert the string into a stream
  vector<string> tokens; // Create vector to hold our words
  while (ss >> buf)
    tokens.push_back(buf);
  return tokens;
}

string dec_to_base_k(int num, int K) {
   // num stores a value in base 10
   // solution will have digits in an array
  int index = 0;
  int remainder;
  stringstream digit;
  while ( num != 0 )
  {
    remainder = num % K;  // assume K > 1
    num = num / K;  // integer division
    digit << remainder;
    index++;
  }
  return digit.str();
}

string list_of_numbers(string op) {
  vector<string> v = split_by_space(op);
  string d;
  int n = atoi(v[0].c_str());
  int k = atoi(v[1].c_str());
  int base = 2;
  while (base <= n)
  {
    d = dec_to_base_k(n, base);
    if (d.size() == k)
      return "YES";
    if (d.size() < k)
      break;
    base++;
  }
  return "NO";
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    char inp[256];
    string line;
    string s;
    cin >> line;
    if (line == "0")
      return 0;
    while (cin) {
      cin.getline(inp, 256);
      line = inp;
      if (line.size() < 1)
        continue;
      // cout << line << endl;
      cout << list_of_numbers(line) << endl;
    }
    return 0;
}
