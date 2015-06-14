#!/bin/bash

if [ -z "$1" ] ; then
    ./find_digits < test.txt
else
    TEST_F="test_$1.txt"
    ./find_digits < $TEST_F
fi
