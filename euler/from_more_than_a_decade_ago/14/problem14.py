#Problem 14
#The following iterative sequence is defined for the set of positive integers:
#
#n  n/2 (n is even)
#n  3n + 1 (n is odd)
#
#Using the rule above and starting with 13, we generate the following sequence:
#
#13  40  20  10  5  16  8  4  2  1
#It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
#Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
#
#Which starting number, under one million, produces the longest chain?
#
#NOTE: Once the chain starts the terms are allowed to go above one million.
#-------------------------------------------------------------------------------
DEBUG = 0

def collatz(n):
    if n == 0:
        return [0]
    i = 0
    m = [n]
    while n != 1:
        if DEBUG: print n
        if n%2 == 0: #is even
            m.append(n / 2)
            n = n / 2
        else:
            m.append(3*n + 1)
            n = 3*n + 1
        i += 1
    return m
        
    

i = [0,1]
i[0] = 0
best_len = 0

for n in range(1,1000000):
    number = collatz(n)
    if len(number) > best_len:
        best = number
        best_len = len(number)
print 'The best is the number ',best[0],' with a chain long ',best_len,' numbers!'
print '\n'
print best
    
    
    
