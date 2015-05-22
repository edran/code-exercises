#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <limits>

using namespace std;

int get_total_distance(vector<int>* v, int h) {
  int total = 0;
  for (vector<int>::const_iterator i = v->begin(); i != v->end(); i++) {
    total += abs(*i - h);
  }
  return total;
}

int minimum_distance(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<int> tokens;
  while (ss >> buf)
    tokens.push_back(atoi(buf.c_str()));
  tokens.erase(tokens.begin());
  sort(tokens.begin(), tokens.end());
  int min = *tokens.begin();
  int max = *tokens.end();
  int d_min = numeric_limits<int>::max();
  int d = 0;
  for (int i = min; i <= max; i++) {
    d = get_total_distance(&tokens, i);
    if (d < d_min) {
      d_min = d;
    }
  }
  return d_min;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << minimum_distance(&line) << endl;
    }
    return 0;
}
