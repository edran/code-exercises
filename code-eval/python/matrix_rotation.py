import sys
import math
from utils.debug import dprint
from utils.basic import splitby

vprint = lambda x: dprint(x, False)  # raise debugging


def deserialise(matrix):
    dl = len(matrix)
    l = int(math.sqrt(dl))
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
    vprint("LOL: " + str(m))
    rotated = matrix_rotate(m)
    n = serialise(rotated)
    s = " ".join(n)
    print s


test_cases.close()
