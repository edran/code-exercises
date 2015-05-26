#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

char morse_to_char(string s) {
  map<string, char> code;
  code[".-"] = 'A';
  code["-..."] = 'B';
  code["-.-."] = 'C';
  code["-.."] = 'D';
  code["."] = 'E';
  code["..-."] = 'F';
  code["--."] = 'G';
  code["...."] = 'H';
  code[".."] = 'I';
  code[".---"] = 'J';
  code["-.-"] = 'K';
  code[".-.."] = 'L';
  code["--"] = 'M';
  code["-."] = 'N';
  code["---"] = 'O';
  code[".--."] = 'P';
  code["--.-"] = 'Q';
  code[".-."] = 'R';
  code["..."] = 'S';
  code["-"] = 'T';
  code["..-"] = 'U';
  code["...-"] = 'V';
  code[".--"] = 'W';
  code["-..-"] = 'X';
  code["-.--"] = 'Y';
  code["--.."] = 'Z';
  code[".----"] = '1';
  code["..---"] = '2';
  code["...--"] = '3';
  code["....-"] = '4';
  code["....."] = '5';
  code["-...."] = '6';
  code["--..."] = '7';
  code["---.."] = '8';
  code["----."] = '9';
  code["-----"] = '0';
  return code[s];
}

string morse_code(string line) {
  bool was_space = false;
  string temp = "";
  stringstream ss;
  for(size_t i = 0; i < line.size(); i++)
  {
    if (line[i] == ' ')
    {
      if(was_space)
        ss << " ";
      else
      {
        ss << morse_to_char(temp);
        temp = "";
        was_space = true;
      }
    }
    else
    {
      temp += line[i];
      was_space = false;
    }
  }
  if (temp.size() > 0)
    ss << morse_to_char(temp);
  return ss.str();
}

int main(int argc, char *argv[]) {
  ifstream stream(argv[1]);
  string line;
  while (getline(stream, line)) {
    cout << morse_code(line) << endl;
  }
  return 0;
}
