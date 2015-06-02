#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int sum_of_digits(string* line) {
  int sum = 0;
  for (string::iterator i = line->begin(); i != line->end(); i++)
  {
    sum += *i - '0';
  }
  return sum;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << sum_of_digits(&line) << endl;
    }
    return 0;
}
