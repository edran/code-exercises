#!/bin/bash

set -e

if [ $1 == 'easy' ] ; then
    THIS_DIR="$(pwd)/easy"
elif [ $1 == 'medium' ] ; then
    THIS_DIR="$(pwd)/medium"
elif [ $1 == 'easy' ] ; then
    THIS_DIR="$(pwd)/hard"
else
    echo "Difficulty must be easy|medium|hard"
    exit 1
fi

NAME=$2

MAKEFILE="$THIS_DIR/$NAME/Makefile"
CPP="$THIS_DIR/$NAME/$NAME.cpp"
TEST="$THIS_DIR/$NAME/test.txt"

mkdir -p "$THIS_DIR/$NAME"
touch $TEST

cat > $MAKEFILE << EOM
all:
	g++-4.8 ${NAME}.cpp -o ${NAME}
EOM


cat > $CPP << EOM
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

string ${NAME}(string* line) {
  // split by whitespace
  string buf;
  stringstream ss(*line);
  vector<string> tokens;

  while (ss >> buf)
    tokens.push_back(buf);
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << ${NAME}(&line) << endl;
    }
    return 0;
}
EOM

exit 0
