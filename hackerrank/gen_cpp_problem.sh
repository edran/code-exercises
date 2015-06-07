#!/bin/bash

set -e

if [ $1 == 'algorithms/warmup/' ] ; then
    THIS_DIR="$(pwd)/algorithms/warmup"
elif [ $1 == 'algorithms/search/' ] ; then
    THIS_DIR="$(pwd)/algorithms/search"
elif [ $1 == 'algorithms/strings/' ] ; then
    THIS_DIR="$(pwd)/algorithms/strings"
elif [ $1 == 'algorithms/sorting/' ] ; then
    THIS_DIR="$(pwd)/algorithms/sorting"
elif [ $1 == 'algorithms/graph_theory/' ] ; then
    THIS_DIR="$(pwd)/algorithms/graph_theory"
elif [ $1 == 'algorithms/greedy/' ] ; then
    THIS_DIR="$(pwd)/algorithms/greedy"
elif [ $1 == 'algorithms/dynamic_programming/' ] ; then
    THIS_DIR="$(pwd)/algorithms/dynamic_programming"
elif [ $1 == 'algorithms/bit_manipulation/' ] ; then
    THIS_DIR="$(pwd)/algorithms/bit_manipulation"
elif [ $1 == 'algorithms/regex/' ] ; then
    THIS_DIR="$(pwd)/algorithms/regex"
elif [ $1 == 'algorithms/number_theory/' ] ; then
    THIS_DIR="$(pwd)/algorithms/number_theory"
elif [ $1 == 'algorithms/combinatorics/' ] ; then
    THIS_DIR="$(pwd)/algorithms/combinatorics"
elif [ $1 == 'algorithms/summations_and_algebra/' ] ; then
    THIS_DIR="$(pwd)/algorithms/summations_and_algebra"
elif [ $1 == 'algorithms/geometry/' ] ; then
    THIS_DIR="$(pwd)/algorithms/geometry"
elif [ $1 == 'algorithms/probability/' ] ; then
    THIS_DIR="$(pwd)/algorithms/probability"
elif [ $1 == 'algorithms/game_theory/' ] ; then
    THIS_DIR="$(pwd)/algorithms/game_theory"
elif [ $1 == 'algorithms/np_complete/' ] ; then
    THIS_DIR="$(pwd)/algorithms/np_complete"
elif [ $1 == 'algorithms/code_golf/' ] ; then
    THIS_DIR="$(pwd)/algorithms/code_golf"
elif [ $1 == 'algorithms/multiple_choice/' ] ; then
    THIS_DIR="$(pwd)/algorithms/multiple_choice"
elif [ $1 == 'algorithms/data_structures_advanced/' ] ; then
    THIS_DIR="$(pwd)/algorithms/data_structures_advanced"
else
    echo "Wrong domain. Check the script please!"
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
	g++-4.9 -std=c++0x ${NAME}.cpp -o ${NAME}
EOM


cat > $CPP << EOM
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solveMeSecond(int a, int b) {
  return a+b;
}

int main() {
  int num1, num2;
  int sum;
  int t;
  cin >> t;

  for (int i=0; i<t; i++) {
    cin >> num1 >> num2;
    sum = solveMeSecond(num1,num2);
    cout << sum << endl;
  }

  return 0;
}

EOM

exit 0
