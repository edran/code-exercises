#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int total = 0;
    while (getline(stream, line)) {
      total += atoi(line.c_str());
    }
    cout << total << endl;
    return 0;
}
