/* Sample code to read in test cases:  */
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


string parse_line(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;
  string to_return;

  while (ss >> buf)
    tokens.push_back(buf);

  for (vector<string>::const_iterator i = tokens.begin();
       i != tokens.end(); ++i)  {
    string temp = *i;
    char c = *i->begin();
    char b = *i->rbegin();
    temp[0] = b;
    temp[temp.length() - 1] = c;
    to_return = to_return + " " + temp;
  }
  to_return.erase(0,1);
  return to_return;
}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << parse_line(&line) << endl;
    }
    return 0;
}
