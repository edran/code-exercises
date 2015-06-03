#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
using namespace std;

string armstrong_numbers(string* line) {
  int sum = 0;
  int n = line->size();
  for(string::iterator i = line->begin(); i != line->end(); i++)
  {
    sum += pow(*i - '0', n);
  }
  if (sum == atoi(line->c_str()))
    return "True";
  else
    return "False";
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << armstrong_numbers(&line) << endl;
    }
    return 0;
}
