#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int i;
    while (getline(stream, line)) {
      i = atoi(line.c_str());
      if (i % 2 == 0)
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
    return 0;
}
