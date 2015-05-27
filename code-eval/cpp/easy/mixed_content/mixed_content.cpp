#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

bool is_num(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string mixed_content(string* line) {
  stringstream ss;
  std::istringstream ssl(*line);
  std::string token;
  vector<string> tokens;

  while(std::getline(ssl, token, ',')) {
    tokens.push_back(token);
  }

  for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
    if (!is_num(*i))
    {
      ss << *i << ",";
    }
  }

  string temp = ss.str();
  int j = temp.size();
  bool flag;
  if (j > 0) {
    temp.erase(temp.end()-1);
    ss.str(string());
    ss << temp;
    flag = true;
  }
  else {
    flag = false;
  }
  for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
    if (is_num(*i))
    {
      if(flag)
      {
        ss << "|";
        flag = false;
      }
      ss << *i << ",";
    }
  }
  string output = ss.str();
  if (*(output.end()-1) == ',')
    output.erase(output.end()-1);
  return output;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << mixed_content(&line) << endl;
    }
    return 0;
}
