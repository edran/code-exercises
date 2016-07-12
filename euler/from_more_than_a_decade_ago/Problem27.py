# -*- coding: utf-8 -*-
#Problem 27
#Considering quadratics of the form:

#n² + an + b, where |a| < 1000 and |b| < 1000

#where |n| is the modulus/absolute value of n
#e.g. |11| = 11 and |4| = 4
#Find the product of the coefficients, a and b, for the
#quadratic expression that produces the maximum number of
#primes for consecutive values of n, starting with n = 0.
import math
n = 0
MAX = 1000
def is_prime(n):
    #print "c: ", n
    if n <= 1:
        return False
    
    elif n == 2:
        return True
    else:
        is_prime = 1
        maxm = int(math.sqrt(n))+1
        for m in range(2,n):
            if n % m == 0:
                return False
        return True
            

best = 0
for a in range(1,MAX + 1):
    #print "######### a =", a
    for b in range(1,MAX + 1):
        #print "n: ", n
        #print "b: ", b
        if is_prime(b):
            n = 0
            #expr = n*n + a*n + b
            #print "expr = ",expr
            while is_prime(n*n + a*n + b):
                n += 1
            if best < n:
                best = n

                print "Best = ", best
                print "Expr = n*n + ", a,"*n + ", b
                print "Product = ", a*b
                #print "###"
            n = 0
            while is_prime(n*n + a*n - b):
                n += 1
            if best < n:
                best = n
                print "Best = ", best
                print "Expr = n*n + ", a,"*n - ", b
                print "Product = ", a*b
                #print "###"

for a in range(-1,-(MAX + 1),-1):
    #print "######### a =", a
    for b in range(1,MAX + 1):
        #print "n: ", n
        #print "b: ", b
        if is_prime(b):
            n = 0
            #expr = n*n + a*n + b
            #print "expr = ",expr
            while is_prime(n*n + a*n + b):
                n += 1
            if best < n:
                best = n

                print "Best = ", best
                print "Expr = n*n + ", a,"*n + ", b
                print "Product = ", a*b
                #print "###"
            n = 0
            while is_prime(n*n + a*n - b):
                n += 1
            if best < n:
                best = n
                print "Best = ", best
                print "Expr = n*n + ", a,"*n - ", b
                print "Product = ", a*b
                #print "###"
                
        
    
