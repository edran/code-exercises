#!/bin/bash

if [ -z "$1" ] ; then
    python simple_array_sum.py < test.txt
else
    TEST_F="test_$1.txt"
    python simple_array_sum.py < $TEST_F
fi
