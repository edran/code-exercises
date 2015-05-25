#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int major_element(string* line) {
  // split by whitespace
  std::stringstream test(*line);
  std::string segment;
  std::vector<int> seglist;
  while(std::getline(test, segment, ','))
  {
    // cout << "* " << atoi(segment.c_str()) << endl;
    seglist.push_back(atoi(segment.c_str()));
  }
  sort(seglist.begin(), seglist.end());
  /* for (int i = 0; i < seglist.size(); i++) */
  /*   cout << "- " << seglist[i] << endl; */
  int counter = 0;
  int max_counter = 0;
  int max_value = -1;
  int current_value = -1;
  for (vector<int>::iterator i = seglist.begin(); i != seglist.end(); i++) {
    // cout << current_value << endl;
    if (current_value == -1)
      current_value = *i;
    if (*i == current_value)
      counter++;
    else {
      if (counter > max_counter) {
        max_counter = counter;
        max_value = current_value;
      }
      counter = 1;
      current_value = *i;
    }
  }
  // cout << "======== " << max_value << " " << max_counter << endl;
  if (max_counter > seglist.size() / 2)
    return max_value;
  else
    return -1;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int j;
    while (getline(stream, line)) {
      j = major_element(&line);
      if (j == -1)
        cout << "None" << endl;
      else
        cout << j << endl;
    }
    return 0;
}
