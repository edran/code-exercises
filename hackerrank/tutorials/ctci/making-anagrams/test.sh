#!/bin/bash

if [ -z "$1" ] ; then
    python making-anagrams.py < test.txt
else
    TEST_F="test_$1.txt"
    python making-anagrams.py < $TEST_F
fi
