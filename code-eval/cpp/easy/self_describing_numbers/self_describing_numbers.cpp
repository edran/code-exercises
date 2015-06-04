#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int elements_in_string(string s, int j)
{
  int counter = 0;
  int temp;
  for (int i = 0; i < s.size(); i++)
  {
    temp = s[i] - '0';
    if (temp == j)
      counter++;
  }
  return counter;
}

int self_describing_numbers(string line) {
  int elems;
  int temp;
  for (int i = 0; i < line.size(); i++)
  {
    elems = elements_in_string(line, i);
    temp = line[i] - '0';
    if (elems != temp)
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << self_describing_numbers(line) << endl;
    }
    return 0;
}
