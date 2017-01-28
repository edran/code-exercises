#!/bin/bash

if [ -z "$1" ] ; then
    python ransom-note.py < test.txt
else
    TEST_F="test_$1.txt"
    python ransom-note.py < $TEST_F
fi
