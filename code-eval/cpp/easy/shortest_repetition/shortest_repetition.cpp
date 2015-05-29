#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int is_period(string current, string line)
{

  while (line.size() > 0)
  {
    if(line.substr(0, current.size()) == current) {
      line = line.substr(current.size());
    }
    else
      return -1;
  }
  int period = current.size();
  return period;
}

int shortest_repetition(string* line) {
  string current = "";
  int p;
  for (string::iterator i = line->begin(); i != line->end(); i++)
  {
    current = current + *i;
    if ((p = is_period(current, *line)) != -1)
        break;
  }
  return p;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << shortest_repetition(&line) << endl;
    }
    return 0;
}
