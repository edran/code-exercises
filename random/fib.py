from collections import defaultdict
import timeit

N = 50


def fib_memoized(n, l=defaultdict(int)):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif l[n] != 0:
        return l[n]
    l[n] = fib_memoized(n - 1, l) + fib_memoized(n - 2, l)
    return l[n]


# Tail recursion optimisation doesn't seem to be a thing in python :()
def fib_tail_recursive(n, current=1, prev=0):
    if n == 0:
        return prev
    elif n == 1:
        return current
    else:
        return fib_tail_recursive(n - 1,
                                  current + prev,
                                  current)


def fib_naive(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fib_naive(n - 1) + fib_naive(n - 2)


def print_return(foo, n):
    print(foo(n))


def time_function(foo, n):
    assert(isinstance(foo, str))
    print("#### " + foo)
    print("VALUE: "),
    print(timeit.timeit("print_return(%s, %d)" % (foo, n),
                        setup="from __main__ import print_return, %s" % foo,
                        number=1))


def time_me(n):
    time_function("fib_memoized", N)
    time_function("fib_tail_recursive", N)
    # TOO SLOW
    time_function("fib_naive", N)


if __name__ == "__main__":
    time_me(N)
