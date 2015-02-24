import sys


def details(test):
    test = [s.strip() for s in test.splitlines()]
    test = filter(None, test)
    test = [s.split(',') for s in test]
    # print test
    for line in test:
        print parse_line(line)


def parse_line(line):
    result = 0
    while 1:
        new = []
        for l in line:
            if "XY" in l:
                return result
            else:
                n = make_move(l)
                new.append(n)
        result += 1
        line = new


def make_move(s):
    is_dots = False
    ns = ""
    for c in s:
        if c == '.' and not is_dots:
            is_dots = True
        elif c == '.' and is_dots:
            ns += c
        else:
            ns += c
    return ns

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    details(test)

test_cases.close()
