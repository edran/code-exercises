#!/bin/bash

if [ -z "$1" ] ; then
    python apple_and_orange.py < test.txt
else
    TEST_F="test_$1.txt"
    python apple_and_orange.py < $TEST_F
fi
