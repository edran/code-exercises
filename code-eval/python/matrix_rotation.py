import sys
import math


def splitby(list, size):
    """
    Split list in n chunks.
    """
    return [list[i:i+size] for i in range(0, len(list), size)]


def deserialise(matrix):
    dl = len(matrix)
    l = int(math.ceil(math.sqrt(dl)))
    return splitby(matrix, l)


def serialise(matrix):
    m = []
    for r in matrix:
        m = m + list(r)
    return m


def matrix_rotate(matrix):
    return zip(*matrix[::-1])  # transpose and invert

###

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    test = test[:-1]
    test = test.split(" ")
    m = deserialise(test)
    n = serialise(matrix_rotate(deserialise(test)))
    s = " ".join(n)
    print(s)

test_cases.close()
