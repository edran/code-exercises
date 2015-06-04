#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int lowest_unique_number(string* line) {
  // split by whitespace
  string buf;
  stringstream sts(*line);
  vector<int> tokens;
  vector<int> orig;
  while (sts >> buf)
    tokens.push_back(atoi(buf.c_str()));
  orig = tokens;
  sort(tokens.begin(), tokens.end());
  int lowest = -1;
  vector<int> uniques;
  int current_val = -1;
  int counter = 0;

  for (int i = 0; i < tokens.size(); i++)
  {
    if(current_val != tokens[i])
    {
      if (1 == counter)
      {
        break;
      }
      counter = 1;
      current_val = tokens[i];
    }
    else
      counter++;
  }
  if (1 == counter)
    lowest = current_val;
  if (-1 == lowest)
    return 0;
  else
    return find(orig.begin(), orig.end(), lowest) - orig.begin() + 1;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << lowest_unique_number(&line) << endl;
    }
    return 0;
}
