#!/bin/bash

if [ -z "$1" ] ; then
    python balanced-brackets.py < test.txt
else
    TEST_F="test_$1.txt"
    python balanced-brackets.py < $TEST_F
fi
