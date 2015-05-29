#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int start = 1; // must be odd
  int end = 99;
  int counter = start;
  while (counter <= end)
  {
    cout << counter << endl;
    counter += 2;
  }
  return 0;
}
