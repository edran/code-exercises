#!/bin/bash

if [ -z "$1" ] ; then
    python divisible_sum_pairs.py < test.txt
else
    TEST_F="test_$1.txt"
    python divisible_sum_pairs.py < $TEST_F
fi
