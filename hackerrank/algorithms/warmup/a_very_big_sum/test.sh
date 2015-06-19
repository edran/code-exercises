#!/bin/bash

if [ -z "$1" ] ; then
    ./a_very_big_sum < test.txt
else
    TEST_F="test_$1.txt"
    ./a_very_big_sum < $TEST_F
fi
