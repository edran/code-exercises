#!/bin/bash

if [ -z "$1" ] ; then
    ./library_fine < test.txt
else
    TEST_F="test_$1.txt"
    ./library_fine < $TEST_F
fi
