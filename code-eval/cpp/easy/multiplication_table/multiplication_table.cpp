#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;

string multiplication_table(int n) {
  stringstream ss;
  for(int i = 1; i < 13; i++)
  {
    if (i < 2)
      ss << n*i;
    else
      ss << setw(4) << n*i;
  }
  return ss.str();
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    for(int i = 1; i < 13; i++)
    {
      cout << multiplication_table(i) << endl;
    }
    return 0;
}
