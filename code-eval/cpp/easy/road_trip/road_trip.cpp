#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;

string road_trip(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);

  vector<int> distances;
  for (vector<string>::iterator i = tokens.begin(); i != tokens.end(); i++)
  {
      stringstream token_ss(*i);
      std::string segment;
      std::vector<std::string> seglist;

      while(std::getline(token_ss, segment, ','))
      {
        seglist.push_back(segment);
      }
      distances.push_back(atoi(seglist[1].c_str()));
  }
  sort(distances.begin(), distances.end());
  distances.insert(distances.begin(), 0);

  stringstream d;
  for (size_t j = 1; j < distances.size(); j++)
  {
    int di = distances[j] - distances[j-1];
    d << di << ",";
  }
  string trip = d.str();
  trip.erase(trip.end() - 1);
  return trip;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << road_trip(&line) << endl;
    }
    return 0;
}
