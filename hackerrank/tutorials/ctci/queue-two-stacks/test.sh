#!/bin/bash

if [ -z "$1" ] ; then
    python queue-two-stacks.py < test.txt
else
    TEST_F="test_$1.txt"
    python queue-two-stacks.py < $TEST_F
fi
