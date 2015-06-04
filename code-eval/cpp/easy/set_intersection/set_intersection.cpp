#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

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
vector<int> i_split_by_char(string s, char c) {
  std::stringstream ss(s);
  std::string segment;
  std::vector<int> seglist;
  while(std::getline(ss, segment, c))
  {
    seglist.push_back(atoi(segment.c_str()));
  }
  return seglist;
}
void set_intersection(string* line) {
  vector<string> sets = split_by_char(*line, ';');
  vector<int> fst = i_split_by_char(sets[0], ',');
  vector<int> snd = i_split_by_char(sets[1], ',');
  vector<int> v(max(fst.size(), snd.size()));
  vector<int>::iterator it = set_intersection(fst.begin(), fst.end(),
                                              snd.begin(), snd.end(),
                                              v.begin());
  v.resize(it-v.begin());
  bool flag = true;
  for(vector<int>::iterator i = v.begin(); i != v.end(); i++)
  {
    if (flag)
    {
      cout << *i;
      flag = false;
    }
    else
      cout << "," << *i;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      set_intersection(&line);
    }
    return 0;
}
