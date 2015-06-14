#!/bin/bash

if [ -z "$1" ] ; then
    ./diagonal_difference < test.txt
else
    TEST="test_$1.txt"
    ./diagonal_difference < $TEST
fi
