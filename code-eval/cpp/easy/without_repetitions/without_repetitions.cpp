#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string without_repetitions(string line) {
  string s = "";
  char prev = ' ';
  char c;
  for (unsigned int i = 0; i < line.size(); i++) {
    c = line[i];
    if (prev != c) {
      s += c;
      prev = c;
    }
  }
  return s;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << without_repetitions(line) << endl;
    }
    return 0;
}
