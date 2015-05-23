#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

int s_to_sec(string data) {
  stringstream d(data);
  string segment;
  vector<int> parsed;
  while(getline(d, segment, ':'))
  {
    parsed.push_back(atoi(segment.c_str()));
  }
  int date = 3600 * parsed[0] + 60 * parsed[1] + parsed[2];
  return date;
}

string tab_int(int i) {
  stringstream ss;
  ss << i;
  string str = ss.str();
  if (str.length() < 2) {
    str = "0" + str;
  }
  return str;
}

string sec_to_s(int date) {
  string s;
  int hours = (date / 60 / 60) % 24;
  int minutes = (date / 60) % 60;
  int seconds = date % 60;
  stringstream ss;
  ss << tab_int(hours) << ":" << tab_int(minutes) << ":" << tab_int(seconds);
  string str = ss.str();
  return str;
}

string delta_time(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  int prev = s_to_sec(tokens[0]);
  int succ = s_to_sec(tokens[1]);
  int diff = abs(prev - succ);
  return sec_to_s(diff);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << delta_time(&line) << endl;
    }
    return 0;
}
