#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cctype>

using namespace std;

string swap_case(string line) {
  string s;
  for (string::iterator i = line.begin(); i != line.end(); i++)
  {
    if (isalpha(*i))
    {
      if(isupper(*i))
        s += tolower(*i);
      else
        s += toupper(*i);
    }
    else
      s += *i;
  }
  return s;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << swap_case(line) << endl;
    }
    return 0;
}
