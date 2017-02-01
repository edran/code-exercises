#!/bin/bash

if [ -z "$1" ] ; then
    python3 bubble-sort.py < test.txt
else
    TEST_F="test_$1.txt"
    python3 bubble-sort.py < $TEST_F
fi
