#!/bin/bash

if [ -z "$1" ] ; then
    python is_binary_search_tree.py < test.txt
else
    TEST_F="test_$1.txt"
    python is_binary_search_tree.py < $TEST_F
fi
