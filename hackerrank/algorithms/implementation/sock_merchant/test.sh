#!/bin/bash

if [ -z "$1" ] ; then
    python sock_merchant.py < test.txt
else
    TEST_F="test_$1.txt"
    python sock_merchant.py < $TEST_F
fi
