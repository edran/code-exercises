#!/bin/bash

if [ -z "$1" ] ; then
    ./time_conversion < test.txt
else
    TEST_F="test_$1.txt"
    ./time_conversion < $TEST_F
fi
