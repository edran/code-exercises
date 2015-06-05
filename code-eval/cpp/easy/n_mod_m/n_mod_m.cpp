#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

vector<int> split_by_char(string s, char c) {
  std::stringstream ss(s);
  std::string segment;
  std::vector<int> seglist;
  while(std::getline(ss, segment, c))
  {
    seglist.push_back(atoi(segment.c_str()));
  }
  return seglist;
}

int n_mod_m(string* line) {
  vector<int> tokens = split_by_char(*line, ',');
  tokens[0] = abs(tokens[0]);
  tokens[1] = abs(tokens[1]);
  int rest = tokens[0];
  while(rest >= tokens[1])
  {
    rest -= tokens[1];
  }
  return rest;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << n_mod_m(&line) << endl;
    }
    return 0;
}
