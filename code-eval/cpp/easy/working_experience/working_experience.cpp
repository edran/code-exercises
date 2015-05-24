#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <list>
#include <unistd.h>

using namespace std;

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

string get_month(int i) {
  string m[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  return m[i-1];
}


list<string> gen_range(int s_month, int s_year, int e_month, int e_year) {
  list<string> generated;
  string buf = "";
  string end = SSTR(get_month(e_month)) + SSTR(e_year);
  // cout << end << endl;
  int i = s_month;
  string new_buf = "";
  string current_y = SSTR(s_year);
  string current;
  while (buf != end) {
    current = SSTR(get_month(i)) + current_y;
    // cout << current << endl;
    // usleep(1000000);
    generated.push_back(current);
    buf = current;
    if (i == 12) {
      i = 1;
      int y = atoi(current_y.c_str());
      current_y = SSTR(y + 1);
    }
    else
      i += 1;
  }
  return generated;
}

list<string> parse_range(string s) {
  // bleah
  string m[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  vector<string> months;
  months.assign(m, m+12);

  if(s[0] == ' ') {
    s.erase(0,1);
  }
  int s_month = find(months.begin(), months.end(), s.substr(0, 3)) \
                - months.begin() + 1;
  int e_month = find(months.begin(), months.end(), s.substr(9, 3)) \
                - months.begin() + 1;

  int s_year = atoi(s.substr(4, 4).c_str());
  int e_year = atoi(s.substr(13, 4).c_str());
  /* cout << s_month << " " << s_year << " " << e_month    \ */
  /*      << " " << e_year << endl; */
  list<string> l = gen_range(s_month, s_year, e_month, e_year);
  // cout << "S = " << l.size() << endl;
  return l;
}


void print(const list<string>& s) {
	list<string>::const_iterator i;
	for( i = s.begin(); i != s.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

int working_experience(string* line) {
  stringstream data(*line);
  string segment;
  vector<string> seglist;

  list<string> total_months;
  while(getline(data, segment, ';'))
  {
    list<string> temp = parse_range(segment);

    total_months.insert(total_months.end(), temp.begin(), temp.end());
  }
  // print(total_months);
  total_months.sort();
  total_months.unique();
  // print(total_months);
  return floor(total_months.size() / 12);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << working_experience(&line) << endl;
    }
    return 0;
}
