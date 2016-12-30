#!/bin/bash

if [ -z "$1" ] ; then
    python tutorial_intro.py < test.txt
else
    TEST_F="test_$1.txt"
    python tutorial_intro.py < $TEST_F
fi
