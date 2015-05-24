#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <bitset>
#include <cmath>

using namespace std;

unsigned long long bin_to_dec(string bin) {
  unsigned long long num = 0;
  for(int i = bin.size()-1; i >= 0; i--){
    num += pow(2, bin.size() - i - 1) * (bin[i] - '0');
  }
  return num;
}

string get_binary(vector<string> v) {
  string bin = "";
  bool is_label = 1;
  int to_print = 0;
  string s = "";
  for (int i = 0; i < v.size(); i++) {
    if (i % 2 == 0)
      is_label = 1;
    else
      is_label = 0;
    if (is_label) {
      if (v[i] == "00")
        to_print = 1;
      else
        to_print = 0;
    }
    else {
      s= v[i];
      for(size_t j = 0; j < s.size(); j++) {
        bin += to_print + 48;
      }
    }
  }
  return bin;
}

unsigned long long juggling_with_zeros(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  string bin = get_binary(tokens);
  unsigned long long dec = bin_to_dec(bin);
  return dec;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << juggling_with_zeros(&line) << endl;
    }
    return 0;
}
