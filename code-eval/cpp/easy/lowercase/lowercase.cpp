#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string lowercase(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  stringstream out;
  for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
    transform(i->begin(), i->end(), i->begin(), ::tolower);
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
      cout << lowercase(&line) << endl;
    }
    return 0;
}
