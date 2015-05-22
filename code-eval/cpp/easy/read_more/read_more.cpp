#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string read_more(string line) {
  size_t s = line.size();
  if (s <= 55) {
    return line;
  }
  string cut = line.substr(0, 40);
  cut = cut.substr(0, cut.rfind(" ")) + "... <Read More>";
  return cut;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << read_more(line) << endl;
    }
    return 0;
}
