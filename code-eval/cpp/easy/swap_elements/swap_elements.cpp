#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> split_by_space(string s) {
  string buf; // Have a buffer string
  stringstream ss(s); // Insert the string into a stream
  vector<int> tokens; // Create vector to hold our words
  while (ss >> buf)
    tokens.push_back(atoi(buf.c_str()));
  return tokens;
}

vector<string> split_by_char(string s, char c) {
  std::stringstream ss(s);
  std::string segment;
  std::vector<std::string> seglist;
  while(std::getline(ss, segment, c))
  {
    seglist.push_back(segment);
  }
  return seglist;
}

vector<int> swap(vector<int> nums, string swap)
{
  if (swap[0] == ' ')
    swap.erase(swap.begin());
  vector<string> v = split_by_char(swap, '-');
  int first = atoi(v[0].c_str());
  int second = atoi(v[1].c_str());
  int temp = nums[first];
  nums[first] = nums[second];
  nums[second] = temp;
  return nums;
}

string swap_elements(string* line) {
  // split by whitespace
  vector<string> v = split_by_char(*line, ':');
  vector<string> swaps = split_by_char(v[1], ',');
  vector<int> nums = split_by_space(v[0]);
  for (vector<string>::iterator i = swaps.begin(); i != swaps.end(); i++)
  {
    nums = swap(nums, *i);
  }
  stringstream ss;
  for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
  {
    ss << *i << " ";
  }
  string out = ss.str();
  out.erase(out.end() - 1);
  return out;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << swap_elements(&line) << endl;
    }
    return 0;
}
