#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <bitset>

using namespace std;

string bit_position(string line) {
  stringstream ss(line);
  std::string segment;
  std::vector<std::string> seglist;

  while(getline(ss, segment, ','))
  {
    seglist.push_back(segment);
  }

  int dec = atoi(seglist[0].c_str());
  int fst = atoi(seglist[1].c_str());
  int snd = atoi(seglist[2].c_str());
  string s = bitset<64>(dec).to_string();
  // s.erase(0, s.find_first_not_of('0'));
  if (s[s.size() - fst] == s[s.size() - snd])
    return "true";
  else
    return "false";
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string ss;
    while (getline(stream, ss)) {
      cout << bit_position(ss) << endl;
    }
    return 0;
}
