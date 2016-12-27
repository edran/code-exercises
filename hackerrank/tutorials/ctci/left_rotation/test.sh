#!/bin/bash

if [ -z "$1" ] ; then
    python left_rotation.py < test.txt
else
    TEST_F="test_$1.txt"
    python left_rotation.py < $TEST_F
fi
