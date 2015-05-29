#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string longest_word(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  int biggest_length = 0;
  string biggest_word = "";
  for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
    if (i->size() > biggest_length)
    {
      biggest_length = i->size();
      biggest_word = *i;
    }
  }
  return biggest_word;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << longest_word(&line) << endl;
    }
    return 0;
}
