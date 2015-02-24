import sys
import string

global DEBUG
DEBUG = False


def dprint(s):
    """
    Print only if debug
    """
    global DEBUG
    if DEBUG:
        print(s)


def char2num(c):
    alph = string.ascii_lowercase
    i = alph.index(c)
    return str(i + 1)


def str2num(s):
    n = char2num(s[0])
    return n + s[1]


def num2char(n):
    alph = string.ascii_lowercase
    return alph[int(n) - 1]


def str2char(s):
    n = num2char(s[0])
    return n + s[1]


def remove_bad(poses):
    """
    Remove incorrect poses
    """
    new_poses = []
    ran = range(1, 9)
    dprint(ran)
    for p in poses:
        if p[0] in ran and p[1] in ran:
            new_poses.append(p)
    return new_poses


def tuple2str(t):
    s = ""
    s += str(t[0]) + str(t[1])
    return str2char(s)


def gen_poses(s):
    pose = str2num(s)
    generated = []
    dprint(pose)
    moves = [(-2, 1),
             (-1, 2),
             (1, 2),
             (2, 1),
             (2, -1),
             (1, -2),
             (-1, - 2),
             (-2, -1)]
    n_pose = (int(pose[0]), int(pose[1]))
    sub_tuple = lambda x, y: (x[0] - y[0], x[1] - y[1])
    generated = [sub_tuple(n_pose, m) for m in moves]
    dprint(generated)
    generated = remove_bad(generated)
    dprint(generated)
    generated = [tuple2str(t) for t in generated]
    generated.sort()
    return generated


def knight_moves(test):
    """
    Return string of space separated possible positions
    """
    test = test[:2]  # strip '\n'
    dprint(test)
    lp = gen_poses(test)

    return " ".join(lp)

###

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    print(knight_moves(test))

test_cases.close()
