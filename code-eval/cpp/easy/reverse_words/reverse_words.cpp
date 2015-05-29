#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string reverse_words(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);
  stringstream out;
  for(vector<string>::reverse_iterator i = tokens.rbegin(); i != tokens.rend(); i++)
  {
    out << *i << " ";
  }
  string o = out.str();
  o.erase(o.end() - 1);
  return o;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << reverse_words(&line) << endl;
    }
    return 0;
}
