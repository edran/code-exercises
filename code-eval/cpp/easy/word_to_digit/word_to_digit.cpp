#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string word_to_digit(string* line) {
  std::stringstream test(*line);
  std::string segment;
  std::vector<std::string> seglist;

  while(std::getline(test, segment, ';'))
  {
    seglist.push_back(segment);
  }
  stringstream ss;
  for (vector<string>::iterator i = seglist.begin(); i != seglist.end(); i++)
  {
    if (*i == "zero")
      ss << 0;
    else if (*i == "one")
      ss << 1;
    else if (*i == "two")
      ss << 2;
    else if (*i == "three")
      ss << 3;
    else if (*i == "four")
      ss << 4;
    else if (*i == "five")
      ss << 5;
    else if (*i == "six")
      ss << 6;
    else if (*i == "seven")
      ss << 7;
    else if (*i == "eight")
      ss << 8;
    else if (*i == "nine")
      ss << 9;
  }
  return ss.str();
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << word_to_digit(&line) << endl;
    }
    return 0;
}
