#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cctype>

using namespace std;

string hidden_digits(string* line) {
  stringstream ss;
  string digits = "abcdefghij";

  for (string::iterator i = line->begin(); i != line->end(); i++)
  {
    int index = digits.find(*i);
    if (isdigit(*i))
    {
      ss <<  *i;
    }
    else if (index != -1)
    {
      ss << index;
    }
  }
  string output = ss.str();
  if (output.size() > 0)
    return ss.str();
  else
    return "NONE";
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << hidden_digits(&line) << endl;
    }
    return 0;
}
