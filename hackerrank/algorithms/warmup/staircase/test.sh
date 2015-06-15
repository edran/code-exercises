#!/bin/bash

if [ -z "$1" ] ; then
    ./staircase < test.txt
else
    TEST_F="test_$1.txt"
    ./staircase < $TEST_F
fi
