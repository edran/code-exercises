#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int happy_numbers(string line, vector<int> *v) {
  int s = 0;
  stringstream ss;
  for (string::iterator i = line.begin(); i != line.end(); i++)
  {
    s += (*i - '0') * (*i - '0');
  }
  if (1 == s)
    return 1;
  else if (find(v->begin(), v->end(), s) != v->end() && v->size() > 0)
    return 0;
  else
  {
    v->push_back(s);
    ss << s;
    return happy_numbers(ss.str(), v);
  }
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      vector<int> v;
      cout << happy_numbers(line, &v) << endl;
    }
    return 0;
}
