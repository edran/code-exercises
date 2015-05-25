#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<string> racing_chars(vector<string>* line) {
  vector<string> after;
  int previous = 25; // won't appear, by constraints
  string temp;
  for(vector<string>::iterator i = line->begin(); i != line->end(); i++) {
    int c = i->find('C');
    int u = i->find('_');
    int j;
    if (c != -1)
      j = c;
    else
      j = u;
    if (j != -1) {
      temp = *i;
      if (previous == 25 || previous == j)
        temp[j] = '|';
      else if (j > previous)
        temp[j] = '\\';
      else
        temp[j] = '/';
    }
    else {
      cout << "Something bad has happened here..." << endl;
    }
    after.push_back(temp);
    previous = j;
  }
  return after;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    vector<string> v;
    while (getline(stream, line)) {
      v.push_back(line);
    }
    vector<string> after = racing_chars(&v);
    for (vector<string>::iterator i = after.begin(); i != after.end(); i++) {
      cout << *i << endl;
    }
    return 0;
}
