#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string roman_numerals(string s) {
  stringstream ss;
  int n = atoi(s.c_str());
  while (n > 0)
  {
    if (n >= 1000)
    {
      ss << "M";
      n -= 1000;
    }
    else if (n >= 900)
    {
      ss << "CM";
      n -= 900;
    }
    else if (n >= 500)
    {
      ss << "D";
      n -= 500;
    }
    else if (n >= 400)
    {
      ss << "CD";
      n -= 400;
    }
    else if (n >= 100)
    {
      ss << "C";
      n -= 100;
    }
    else if (n >= 90)
    {
      ss << "XC";
      n -= 90;
    }
    else if (n >= 50)
    {
      ss << "L";
      n -= 50;
    }
    else if (n >= 40)
    {
      ss << "XL";
      n -= 40;
    }
    else if (n >= 10)
    {
      ss << "X";
      n -= 10;
    }
    else if (n >= 9)
    {
      ss << "IX";
      n -= 9;
    }
    else if (n >= 5)
    {
      ss << "V";
      n -= 5;
    }
    else if (n >= 4)
    {
      ss << "IV";
      n -= 4;
    }
    else if (n >= 1)
    {
      ss << "I";
      n -= 1;
    }
  }
  return ss.str();
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << roman_numerals(line) << endl;
    }
    return 0;
}
