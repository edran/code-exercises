#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <string>

using namespace std;

string tab_int(int i) {
  stringstream ss;
  ss << i;
  string str = ss.str();
  if (str.length() < 2) {
    str = "0" + str;
  }
  return str;
}

string nice_angles(string line) {
  double value = atof(line.c_str());
  stringstream ss;
  string converted;
  int hours =  floor(value);
  int minutes = floor((value - hours) * 60);
  int seconds = floor((value - hours - minutes/60.0) * 3600);
  ss << hours << "." << tab_int(minutes) << '\'' << tab_int(seconds) << '"';
  ss >> converted;
  return converted;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << nice_angles(line) << endl;
    }
    return 0;
}
