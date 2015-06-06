#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

string redundant_or_not(map<long, bool> *m, long line) {

  std::pair<std::map<long, bool>::iterator,bool> ret;
  ret = m->insert(pair<long, bool>(line, 1));
  if (ret.second)
    return "ADDED";
  else
    return "REDUNDANT";
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    map<long, bool> m;
    bool flag = false;
    // while (cin>>line) {
    while (getline(stream, line)) {
      if (!flag) {
        flag = true;
      }
      else
        cout << redundant_or_not(&m , atoi(line.c_str())) << endl;
    }
    return 0;
}
