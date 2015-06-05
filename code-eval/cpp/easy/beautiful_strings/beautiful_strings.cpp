#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cctype>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool pairCompare(const pair<char, int>& firstElem,
                 const pair<char, int>& secondElem) {
  return firstElem.second > secondElem.second;
}

int beautiful_strings(string line) {
  map<char, int> added;
  transform(line.begin(), line.end(), line.begin(), ::tolower);
  for(string::iterator i = line.begin(); i != line.end(); i++)
  {
    if (!isalpha(*i))
      continue;
    if (added.find(*i) == added.end())
    {
      added[*i] = 1;
    }
    else
    {
      added[*i]++;
    }
  }
  vector<pair<char, int> > v;
  copy(added.begin(), added.end(), back_inserter(v));
  sort(v.begin(), v.end(), pairCompare);
  vector<char> res;
  for (int i = 0; i < v.size(); i++)
  {
    res.push_back(v[i].first);
  }
  int sum = 0;
  for(string::iterator i = line.begin(); i != line.end(); i++)
  {
    if (!isalpha(*i))
      continue;
    int index = find(res.begin(), res.end(), *i) - res.begin();
    sum += 26 - index;
  }
  return sum;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << beautiful_strings(line) << endl;
    }
    return 0;
}
