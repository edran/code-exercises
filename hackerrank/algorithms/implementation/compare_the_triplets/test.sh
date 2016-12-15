#!/bin/bash

if [ -z "$1" ] ; then
    python compare_the_triplets.py < test.txt
else
    TEST_F="test_$1.txt"
    python compare_the_triplets.py < $TEST_F
fi
