#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string get_direction(int O, int P, int Q, int R) {
  if (O == Q && P == R)
    return "here";
  string s = "";
  if (R > P) {
    s = s + "N";
  }
  else if (R < P){
    s = s + "S";
  }
  if (Q > O) {
    s = s + "E";
  }
  else if (Q < O){
    s = s + "W";
  }
  return s;
}

string compare_points(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  int O = atoi(tokens[0].c_str());
  int P = atoi(tokens[1].c_str());
  int Q = atoi(tokens[2].c_str());
  int R = atoi(tokens[3].c_str());

  return get_direction(O, P, Q, R);
}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << compare_points(&line) << endl;
    }
    return 0;
}
