#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int hex_to_decimal(string* line) {
  std::stringstream str;
  str << *line;
  int value;
  str >> std::hex >> value;
  return value;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << hex_to_decimal(&line) << endl;
    }
    return 0;
}
