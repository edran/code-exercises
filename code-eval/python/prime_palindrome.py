"""
print largest prime palindrome < n
"""

import math


def is_palindrome(n):
    
    n = str(n)
    l = len(n)

    for i in range(int(math.ceil(l/2.0))):
        if n[i] != n[l - 1 - i]:
            return False
        
    return True

def is_prime(n):
    for i in range(2,n):
        if n % i == 0:
            return False
    return True

if __name__ == "__main__":

    num = 1000
    n = 0
    
    for i in range(1, num+1):
        
        # print i, is_palindrome(i), is_prime(i)
        if is_palindrome(i) and is_prime(i):
            
            n = max(n, i)

    print n
