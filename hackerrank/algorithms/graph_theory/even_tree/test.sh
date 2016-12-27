#!/bin/bash

if [ -z "$1" ] ; then
    python even_tree.py < test.txt
else
    TEST_F="test_$1.txt"
    python even_tree.py < $TEST_F
fi
