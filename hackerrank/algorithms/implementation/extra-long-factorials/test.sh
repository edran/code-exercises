#!/bin/bash

if [ -z "$1" ] ; then
    python extra-long-factorials.py < test.txt
else
    TEST_F="test_$1.txt"
    python extra-long-factorials.py < $TEST_F
fi
