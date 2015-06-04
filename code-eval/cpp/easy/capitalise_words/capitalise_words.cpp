#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cctype>

using namespace std;

string capitalise_words(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  stringstream sout;
  bool flag = true;
  string temp;
  for(vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
    temp = *i;
    temp[0] = toupper(temp[0]);
    if (flag)
    {
      flag = false;
      sout << temp;
    }
    else
      sout << " " << temp;
  }
  return sout.str();
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << capitalise_words(&line) << endl;
    }
    return 0;
}
