#include <iostream>
#include <fstream>

using namespace std;

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

int main(int argc, char *argv[]) {
  cout << filesize(argv[1]) << endl;
      return 0;
}
