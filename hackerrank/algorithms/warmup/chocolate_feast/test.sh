#!/bin/bash

if [ -z "$1" ] ; then
    ./chocolate_feast < test.txt
else
    TEST_F="test_$1.txt"
    ./chocolate_feast < $TEST_F
fi
