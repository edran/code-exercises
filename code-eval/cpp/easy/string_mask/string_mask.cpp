#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string string_mask(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  for (int i = 0; i < tokens[1].size(); i++)
  {
    if (tokens[1][i] == '1')
      tokens[0][i] = toupper(tokens[0][i]);
  }
  return tokens[0];
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << string_mask(&line) << endl;
    }
    return 0;
}
