#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

string simple_sorting(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<float> tokens;

  while (ss >> buf) {
    tokens.push_back(atof(buf.c_str()));
  }
  sort( tokens.begin(), tokens.end() );
  stringstream sout;
  bool flag = true;
  for (vector<float>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
    if (flag) {
      sout << setprecision(3) << fixed << *i;
      flag = false;
    }
    else
      sout << setprecision(3) << fixed << " " << *i;
  }
  return sout.str();
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << simple_sorting(&line) << endl;
    }
    return 0;
}
