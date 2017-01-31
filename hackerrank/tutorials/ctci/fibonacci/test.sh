#!/bin/bash

if [ -z "$1" ] ; then
    python fibonacci.py < test.txt
else
    TEST_F="test_$1.txt"
    python fibonacci.py < $TEST_F
fi
