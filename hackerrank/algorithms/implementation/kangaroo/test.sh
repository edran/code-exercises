#!/bin/bash

if [ -z "$1" ] ; then
    python kangaroo.py < test.txt
else
    TEST_F="test_$1.txt"
    python kangaroo.py < $TEST_F
fi
