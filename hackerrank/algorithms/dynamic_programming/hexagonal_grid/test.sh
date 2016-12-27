#!/bin/bash

if [ -z "$1" ] ; then
    python hexagonal_grid.py < test.txt
else
    TEST_F="test_$1.txt"
    python hexagonal_grid.py < $TEST_F
fi
