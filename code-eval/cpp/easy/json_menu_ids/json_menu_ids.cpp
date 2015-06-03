#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

// cannot use regex because compiler is too old :/

int json_menu_ids(string line) {
  // find id
  // find next label
  // find next }
  // if label_pos < }_pos
  // parse id and sum
  // remove string up to "id"
  int sum = 0;
  size_t curr_id_pos = 1;
  while (1)
  {

    size_t label_pos;
    size_t close_pos;
    string temp;
    curr_id_pos = line.find("\"id\":");
    label_pos = line.find("\"label\":", curr_id_pos);
    close_pos = line.find("}", curr_id_pos);
    if(label_pos == string::npos)
      break;
    if (label_pos < close_pos)
    {
      temp = line.substr(curr_id_pos+6, label_pos - curr_id_pos - 8);
      // cout << temp << endl;
      sum += atoi(temp.c_str());
    }
    line = line.substr(curr_id_pos+5); // remove used id
  }
  return sum;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      if(line.size() > 0)
        cout << json_menu_ids(line) << endl;
    }
    return 0;
}
