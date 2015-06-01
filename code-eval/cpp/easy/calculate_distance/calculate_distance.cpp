#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

vector<string> split_by_space(string s) {
  string buf; // Have a buffer string
  stringstream ss(s); // Insert the string into a stream
  vector<string> tokens; // Create vector to hold our words
  while (ss >> buf)
    tokens.push_back(buf);
  return tokens;
}

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

int calc(int fx, int fy, int sx, int sy) {
  /* cout << fx << ", " << fy << endl; */
  /* cout << sx << ", " << sy << endl; */
  double r = pow(fx - sx, 2) + pow(fy - sy, 2);
  int d = sqrt(r);
  return d;
}

vector<int> parse_pair(string s) {
  // remove parens
  s.erase(0,1);
  s.erase(s.size() - 1);
  vector<string> nums = split_by_char(s, ',');
  vector<int> n;
  n.push_back(atoi(nums[0].c_str()));
  nums[1].erase(0,1);
  n.push_back(atoi(nums[1].c_str()));
  return n;
}

vector<string> split_pairs(string s) {
  size_t pos = s.find(" (");
  vector<string> pairs;
  pairs.push_back(s.substr(0, pos));
  pairs.push_back(s.substr(pos+1));
  return pairs;
}
int calculate_distance(string* line) {
  vector<string> tokens = split_pairs(*line);
  vector<int> first = parse_pair(tokens[0]);
  vector<int> second = parse_pair(tokens[1]);
  return calc(first[0], first[1], second[0], second[1]);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << calculate_distance(&line) << endl;
    }
    return 0;
}
