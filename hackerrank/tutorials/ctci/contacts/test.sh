#!/bin/bash

if [ -z "$1" ] ; then
    python contacts.py < test.txt
else
    TEST_F="test_$1.txt"
    python contacts.py < $TEST_F
fi
