#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

vector<string> split_by_char(string s, char c) {
  std::stringstream ss(s);
  std::string segment;
  std::vector<std::string> seglist;
  while(std::getline(ss, segment, c))
  {
    seglist.push_back(segment);
  }
  return seglist;
}

int rightmost_char(string* line) {
  vector<string> parts = split_by_char(*line, ',');
  char c = parts[1][0];
  return parts[0].find_last_of(c);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << rightmost_char(&line) << endl;
    }
    return 0;
}
