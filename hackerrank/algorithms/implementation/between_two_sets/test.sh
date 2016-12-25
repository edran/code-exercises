#!/bin/bash

if [ -z "$1" ] ; then
    python between_two_sets.py < test.txt
else
    TEST_F="test_$1.txt"
    python between_two_sets.py < $TEST_F
fi
