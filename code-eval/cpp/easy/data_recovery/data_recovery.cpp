#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
    ( std::ostringstream() << std::dec << x ) ).str()

string data_recovery(string* line) {
  stringstream data(*line);
  string segment;
  vector<string> seglist;

  while(getline(data, segment, ';'))
  {
    seglist.push_back(segment);
  }
  // split by whitespace
  string buf;
  stringstream ss(seglist[0]);
  vector<string> word_tokens;

  while (ss >> buf)
    word_tokens.push_back(buf);

  buf = " ";
  stringstream n_ss(seglist[1]);
  vector<string> n_tokens;

  while (n_ss >> buf)
    n_tokens.push_back(buf);

  for (size_t i = 1; i <= word_tokens.size(); i++) {
    int j = find(n_tokens.begin(), n_tokens.end(), SSTR(i)) - n_tokens.begin();
    if (j == n_tokens.size()) {
      n_tokens.push_back(SSTR(i));
    }
  }

  stringstream real;
  for (size_t i = 1; i <= word_tokens.size(); i++) {
    int j = find(n_tokens.begin(), n_tokens.end(), SSTR(i)) - n_tokens.begin();
    real << word_tokens[j] << " ";
  }

  string s = real.str();
  return s.substr(0, s.size()-1);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << data_recovery(&line) << endl;
    }
    return 0;
}
