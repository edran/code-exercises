#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

string unique_elements(string* line) {
  stringstream test(*line);
  string segment;
  vector<int> seglist;

  while(getline(test, segment, ','))
  {
    seglist.push_back(atoi(segment.c_str()));
  }
  sort(seglist.begin(), seglist.end());
  seglist.erase(unique(seglist.begin(), seglist.end()), seglist.end());
  stringstream ss;
  bool flag = true;
  for (vector<int>::iterator i = seglist.begin(); i != seglist.end(); i++)
  {
    if (flag)
    {
      flag = false;
      ss << *i;
    }
    else
      ss << "," << *i;
  }
  return ss.str();
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << unique_elements(&line) << endl;
    }
    return 0;
}
