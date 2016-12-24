#!/bin/bash

if [ -z "$1" ] ; then
    python bon_appetit.py < test.txt
else
    TEST_F="test_$1.txt"
    python bon_appetit.py < $TEST_F
fi
