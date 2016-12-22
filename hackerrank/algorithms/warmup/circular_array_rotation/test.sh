#!/bin/bash

if [ -z "$1" ] ; then
    python circular_array_rotation.py < test.txt
else
    TEST_F="test_$1.txt"
    python circular_array_rotation.py < $TEST_F
fi
