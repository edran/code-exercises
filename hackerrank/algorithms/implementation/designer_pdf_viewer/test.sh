#!/bin/bash

if [ -z "$1" ] ; then
    python designer_pdf_viewer.py < test.txt
else
    TEST_F="test_$1.txt"
    python designer_pdf_viewer.py < $TEST_F
fi
