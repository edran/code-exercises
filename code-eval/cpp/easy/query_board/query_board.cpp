#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

void set_row(int (&matrix)[256][256], int i, int x) {
  for (int k = 0; k < 256; k++)
    matrix[i][k] = x;
  return;
}

void set_col(int (&matrix)[256][256], int j, int x) {
  for (int k = 0; k < 256; k++)
    matrix[k][j] = x;
  return;
}

int query_row(int (&matrix)[256][256], int i) {
  int sum = 0;
  for (int k = 0; k < 256; k++)
    sum += matrix[i][k];
  return sum;
}

int query_col(int (&matrix)[256][256], int j) {
  int sum = 0;
  for (int k = 0; k < 256; k++)
    sum += matrix[k][j];
  return sum;
}

void query_board(string line, int (&matrix)[256][256]) {
  // split by whitespace
  string buf;
  stringstream ss(line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);
  if (tokens[0] == "QueryCol")
  {
  int fst = atoi(tokens[1].c_str());
  cout << query_col(matrix, fst) << endl;
  }
  else if(tokens[0] == "QueryRow")
  {
  int fst = atoi(tokens[1].c_str());
  cout << query_row(matrix, fst) << endl;
  }
  else if(tokens[0] == "SetRow")
  {
  int fst = atoi(tokens[1].c_str());
  int snd = atoi(tokens[2].c_str());
  set_row(matrix, fst, snd);
  }
  else if(tokens[0] == "SetCol")
  {
  int fst = atoi(tokens[1].c_str());
  int snd = atoi(tokens[2].c_str());
  set_col(matrix, fst, snd);
  }
  return;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int matrix[256][256] = {{0}};
    while (getline(stream, line)) {
      query_board(line, matrix);
    }
    return 0;
}
