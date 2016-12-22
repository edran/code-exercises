#!/bin/bash

if [ -z "$1" ] ; then
    python mini_max_sum.py < test.txt
else
    TEST_F="test_$1.txt"
    python mini_max_sum.py < $TEST_F
fi
