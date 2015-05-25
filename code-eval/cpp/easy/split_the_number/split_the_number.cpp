#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int split_the_number(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  int op_index;
  int p = tokens[1].find("+");
  int m = tokens[1].find("-");
  bool is_plus = false;
  if (p != -1) {
    op_index = p;
    is_plus = true;
  }
  else
    op_index = m;
  //  cout << "Index = " << op_index << endl;

  int first = atoi(tokens[0].substr(0, op_index).c_str());
  int second = atoi(tokens[0].substr(op_index).c_str());
  //  cout << "f = " << first << ", s = " << second << endl;
  int total;
  if (is_plus)
    total = first + second;
  else
    total = first - second;
  return total;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << split_the_number(&line) << endl;
    }
    return 0;
}
