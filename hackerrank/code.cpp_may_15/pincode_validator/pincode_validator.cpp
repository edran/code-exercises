#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

void pretty_print(vector<string> *valid) {
  if (valid->size() < 1) {
    cout << "JUNK" << endl;
    return;
  }
  sort(valid->begin(), valid->end());
  valid->erase(unique(valid->begin(),
                      valid->end()),
               valid->end());
  for (string s : *valid) {
    cout << s << endl;
  }
  return;
}

void pincode_validator(string s, vector<string> *valid, regex *re) {
  // cout << "line: " << s << endl;
  sregex_iterator next(s.begin(), s.end(), *re);
  sregex_iterator end;
  string temp;
  while (next != end) {
    std::smatch match = *next;
    temp = match.str();
    valid->push_back(temp);
    next++;
  }
  return;
}

int main(int argc, char *argv[]) {
    char inp[2000000];
    string line;
    vector<string> valid;
    regex re("[[:digit:]]{3}-[[:digit:]]{2}-[[:digit:]]{2}-[[:digit:]]{8}-[A-Z]{1}");
    string n;
    cin >> n;
    while (cin) {
      cin.getline(inp, 200000);
      line = inp;
      if (line.size() < 20)
        continue;
      pincode_validator(line, &valid, &re);
    }
    pretty_print(&valid);
    return 0;
}
