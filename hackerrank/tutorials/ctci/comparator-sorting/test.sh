#!/bin/bash

if [ -z "$1" ] ; then
    python3 comparator-sorting.py < test.txt
else
    TEST_F="test_$1.txt"
    python3 comparator-sorting.py < $TEST_F
fi
