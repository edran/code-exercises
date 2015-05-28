#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> split_by_space(string s) {
  string buf; // Have a buffer string
  stringstream ss(s); // Insert the string into a stream
  vector<int> tokens; // Create vector to hold our words
  while (ss >> buf)
    tokens.push_back(atoi(buf.c_str()));
  return tokens;
}

vector<string> split_by_char(char c, string s) {
  std::stringstream ss(s);
  std::string segment;
  std::vector<std::string> seglist;
  while(std::getline(ss, segment, c))
  {
    seglist.push_back(segment);
  }
  return seglist;
}

string multiply_lists(string* line) {

  vector<string> lists = split_by_char('|', *line);
  vector<int> first = split_by_space(lists[0]);
  vector<int> second = split_by_space(lists[1]);
  stringstream ss;
  for (size_t i = 0; i < first.size(); i++)
  {
    ss << first[i] * second[i] << " ";
  }
  string out = ss.str();
  out.erase(out.end() -1);
  return out;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << multiply_lists(&line) << endl;
    }
    return 0;
}
