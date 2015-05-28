#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>

using namespace std;

int is_prime(int n) {
  bool flag = true;
  for (int i = 2; i <= int (sqrt(n)+1); i++)
  {
    if (n % i == 0)
    {
      flag = false;
      break;
    }
  }
  return flag;
}

int main(int argc, char *argv[]) {
  int sum = 1;
  int counter = 0;
  int current = 1;
  while(counter < 1000)
  {
    if (is_prime(current))
    {
      sum += current;
      counter++;
    }
    current++;
  }
  cout << sum << endl;
}
