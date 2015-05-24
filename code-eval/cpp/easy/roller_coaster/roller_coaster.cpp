#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cctype>

using namespace std;

string roller_coaster(string line) {
  // split by whitespace
  bool flag = 1;
  for (string::iterator i = line.begin(); i != line.end(); i++) {

    if(isalpha(*i)) {
      if (flag) {
        *i = toupper(*i);
        flag = 0;
      }
      else {
        *i = tolower(*i);
        flag = 1;
      }
    }
  }
  return line;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << roller_coaster(line) << endl;
    }
    return 0;
}
