#!/bin/bash

if [ -z "$1" ] ; then
    python find-running-median.py < test.txt
else
    TEST_F="test_$1.txt"
    python find-running-median.py < $TEST_F
fi
