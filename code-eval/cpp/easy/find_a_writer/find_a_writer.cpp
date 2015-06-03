#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> split_by_space(string line)
{
  string buf;
  stringstream ss(line);
  vector<int> tokens;

  while (ss >> buf)
    tokens.push_back(atoi(buf.c_str()));
  return tokens;
}

string find_a_writer(string* line) {
  // split by whitespace
  std::stringstream test(*line);
  std::string segment;
  std::vector<std::string> seglist;

  while(std::getline(test, segment, '|'))
  {
    seglist.push_back(segment);
  }
  seglist[1].erase(0,1);
  vector<int> numbers = split_by_space(seglist[1]);
  string s = seglist[0];
  stringstream sout;
  for (int i = 1; i <= numbers.size(); i++)
  {
    sout << s[numbers[i-1] - 1];
  }
  return sout.str();
}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      if (line.size() > 0)
        cout << find_a_writer(&line) << endl;
    }
    return 0;
}
