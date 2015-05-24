#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string age_distribution(string *line) {
  int value = atoi(line->c_str());
  if (value >= 0 && value <= 2)
    return "Still in Mama's arms";
  if (value >= 3 && value <= 4)
    return "Preschool Maniac";
  if (value >= 0 && value <= 11)
    return "Elementary school'";
  if (value >= 0 && value <= 14)
    return "Middle school";
  if (value >= 0 && value <= 18)
    return "High school";
  if (value >= 0 && value <= 22)
    return "College";
  if (value >= 0 && value <= 65)
    return "Working for the man";
  if (value >= 0 && value <= 100)
    return "The Golden Years";
  return "This program is for humans";
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << age_distribution(&line) << endl;
    }
    return 0;
}
