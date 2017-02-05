from math import sqrt


def is_prime(self, n):
        if n < 2:
            return False
        for i in xrange(2, int(n**0.5) + 1):
            if n % i == 0:
                return False

        return True


def is_prime2(self, num):
    if num < 3:
        return True
    i = 2
    while i <= int(sqrt(num)):
        if num % i == 0:
            return False
        i += 1
    return True


def primes_sieve2(limit):
    a = [True] * limit                          # Initialize the primality list
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in xrange(i*i, limit, i):     # Mark factors non-prime
                a[n] = False


def eratosthenes(n):
    multiples = []
    for i in range(2, n+1):
        if i not in multiples:
            print (i)
            for j in range(i*i, n+1, i):
                multiples.append(j)
