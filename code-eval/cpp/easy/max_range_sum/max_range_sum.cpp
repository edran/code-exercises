#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int get_range_sum(vector<int>* v, int i, int range) {
  int total = 0;
  for (int j = 0; j < range; j++)
    total += (*v)[i + j];
  return total;
}

int max_range_sum(string* line) {
  // split by ;
  int i = line->find(';');
  string r = line->substr(0, i);
  int range = atoi(r.c_str());
  *line = line->substr(i+1);
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<int> tokens;

  while (ss >> buf) {
    tokens.push_back(atoi(buf.c_str()));
  }
  int n = 0;
  int max = 0;
  for (unsigned int i = 0; i <= tokens.size() - range; i++) {
    n = get_range_sum(&tokens, i, range);
    if (n > max)
      max = n;
  }
  return max;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << max_range_sum(&line) << endl;
    }
    return 0;
}
