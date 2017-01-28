#!/bin/bash

if [ -z "$1" ] ; then
    python linked-list-cycle.py < test.txt
else
    TEST_F="test_$1.txt"
    python linked-list-cycle.py < $TEST_F
fi
