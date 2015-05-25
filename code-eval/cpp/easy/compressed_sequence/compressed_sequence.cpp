#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string compressed_sequence(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    // cout << buf << endl;
    tokens.push_back(buf);

  tokens.push_back("DATA"); // allows string creation process in loop
  string current_value = "";
  int counter = 0;
  stringstream ss_compr;

  for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
    if (current_value == "")
      current_value = *i;
    if (current_value == *i) {
      counter++;
    }
    else {
      // cout << counter << " " << current_value << " " << endl;;
      ss_compr << counter << " " << current_value << " ";
      counter = 1;
      current_value = *i;
    }
  }
  string compressed = ss_compr.str();
  compressed = compressed.substr(0, compressed.size() - 1);
  return compressed;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << compressed_sequence(&line) << endl;
    }
    return 0;
}
