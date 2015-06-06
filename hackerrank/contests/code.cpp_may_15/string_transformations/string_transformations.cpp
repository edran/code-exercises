#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

vector<int> split_by_space(string s) {
  string buf; // Have a buffer string
  stringstream ss(s); // Insert the string into a stream
  vector<int> tokens; // Create vector to hold our words
  while (ss >> buf)
    tokens.push_back(atoi(buf.c_str()));
  return tokens;
}

void string_transformations(string *s, string* op) {
  vector<int> v = split_by_space(*op);
  reverse(s->begin() + v[0], s->begin() +  v[1] + 1);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    char inp[256];
    string line;
    string s;
    cin >> s;
    cin >> line;
    while (cin) {
      cin.getline(inp, 256);
      line = inp;
      if (line.size() < 1)
        continue;
      // cout << line << endl;
      string_transformations(&s , &line);
      cout << s << endl;
    }
    return 0;
}
