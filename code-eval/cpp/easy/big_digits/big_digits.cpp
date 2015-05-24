#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<string> get_big_digit(char c) {
  // can probably do something better here, but emacs macros are faster
  const char* zero[] ={"-**--", "*--*-", "*--*-", "*--*-", "-**--", "-----"};
  const char* one[] = {"--*--", "-**--", "--*--", "--*--", "-***-", "-----"};
  const char* two[] = {"***--", "---*-", "-**--", "*----", "****-", "-----"};
  const char* three[]={"***--", "---*-", "-**--", "---*-", "***--", "-----"};
  const char* four[]= {"-*---", "*--*-", "****-", "---*-", "---*-", "-----"};
  const char* five[]= {"****-", "*----", "***--", "---*-", "***--", "-----"};
  const char* six[] = {"-**--", "*----", "***--", "*--*-", "-**--", "-----"};
  const char* seven[]={"****-", "---*-", "--*--", "-*---", "-*---", "-----"};
  const char* eight[]={"-**--", "*--*-", "-**--", "*--*-", "-**--", "-----"};
  const char* nine[]= {"-**--", "*--*-", "-***-", "---*-", "-**--", "-----"};

  vector<string> v_zero(zero, zero + 6);
  vector<string> v_one(one, one + 6);
  vector<string> v_two(two, two + 6);
  vector<string> v_three(three, three + 6);
  vector<string> v_four(four, four + 6);
  vector<string> v_five(five, five + 6);
  vector<string> v_six(six, six + 6);
  vector<string> v_seven(seven, seven + 6);
  vector<string> v_eight(eight, eight + 6);
  vector<string> v_nine(nine, nine + 6);

  switch (c) {
    case '0':
      return v_zero;
    case '1':
      return v_one;
    case '2':
      return v_two;
    case '3':
      return v_three;
    case '4':
      return v_four;
    case '5':
      return v_five;
    case '6':
      return v_six;
    case '7':
      return v_seven;
    case '8':
      return v_eight;
    case '9':
      return v_nine;
    default:
      cout << "Something is broken" << endl;
      return v_zero;
  }
}


vector<string> big_digits(string line) {

  string valid = "0123456789";
  const char *vinit[] = {"", "", "", "", "", ""};
  vector<string> big(vinit, vinit + 6);

  for (unsigned int i = 0; i < line.size(); i++) {
    if (valid.find(line[i]) != -1) {
      vector<string> v = get_big_digit(line[i]);
      for (int j = 0; j < 6; j++) {
        big[j] += v[j];
      }
    }
  }

  return big;

}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      vector<string> v = big_digits(line);
      for(vector<string>::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
      }
    }
    return 0;
}
