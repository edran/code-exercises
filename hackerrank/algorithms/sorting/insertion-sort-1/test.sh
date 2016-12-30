#!/bin/bash

if [ -z "$1" ] ; then
    python insertion-sort-1.py < test.txt
else
    TEST_F="test_$1.txt"
    python insertion-sort-1.py < $TEST_F
fi
