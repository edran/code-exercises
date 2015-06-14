#!/bin/bash

if [ -z "$1" ] ; then
    ./plus_minus < test.txt
else
    TEST_F="test_$1.txt"
    ./plus_minus < $TEST_F
fi
