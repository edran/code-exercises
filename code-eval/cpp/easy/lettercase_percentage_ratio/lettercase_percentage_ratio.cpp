#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

float calculate_upper(string* line) {
  float upper = 0;
  for (string::iterator i = line->begin(); i != line->end(); i++){
    if (isupper(*i))
      upper++;
  }
  float v = (upper / line->size()) * 100.0;
  return v;
}

string lettercase_percentage_ratio(string* line) {
  float up = calculate_upper(line);
  float low = roundf((100 - up) * 100) / 100;
  up = roundf(up * 100) / 100;
  stringstream ss;
  cout << fixed << setprecision(2);
  cout << "lowercase: " << low;
  cout << " uppercase: " << up << endl;
  return ss.str();
}


int main(int argc, char *argv[]) {
  cout << fixed;
  cout << setprecision(2);
  ifstream stream(argv[1]);
  string line;
  while (getline(stream, line)) {
    lettercase_percentage_ratio(&line);
  }
  return 0;
}
