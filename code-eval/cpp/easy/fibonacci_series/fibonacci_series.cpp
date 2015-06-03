#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int fibonacci_series(int n) {
  if (0 == n)
    return 0;
  else if (1 == n)
    return 1;
  else
    return fibonacci_series(n-1) + fibonacci_series(n-2);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string n;
    while (getline(stream, n)) {
      cout << fibonacci_series(atoi(n.c_str())) << endl;
    }
    return 0;
}
