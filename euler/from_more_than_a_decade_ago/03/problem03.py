# -*- coding: utf-8 -*-
#Project Euler - Problem 03
#03 August 2012 - Nantas Nardelli
#--------------------------------------------------------------------------
#The prime factors of 13195 are 5, 7, 13 and 29.
#What is the largest prime factor of the number 600851475143 ?
#--------------------------------------------------------------------------

import math
n = 600851475143
number = int(math.sqrt(600851475143)) + 1
i = 2
flag1 = 0

while i < number:

    if (n % i == 0) and (n / i != 1):
        print i
        n = n / i
        print n
        print '-------'
    i = i + 1
print n
        


