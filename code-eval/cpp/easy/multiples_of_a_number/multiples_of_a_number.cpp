#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> split_by_char(string s, char c) {
  stringstream ss(s);
  string segment;
  vector<int> seglist;
  while(std::getline(ss, segment, c))
  {
    seglist.push_back(atoi(segment.c_str()));
  }
  return seglist;
}


int multiples_of_a_number(string* line) {
  vector<int> v = split_by_char(*line, ',');
  int x = v[0];
  int n = v[1];
  int i = 0;
  int y;
  while(1)
  {
    y = n * i;
    if (y >= x)
      break;
    i++;
  }
  return y;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << multiples_of_a_number(&line) << endl;
    }
    return 0;
}
