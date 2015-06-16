#!/bin/bash

if [ -z "$1" ] ; then
    ./caesar_cipher < test.txt
else
    TEST_F="test_$1.txt"
    ./caesar_cipher < $TEST_F
fi
