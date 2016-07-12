#Problem 21
#Let d(n) be defined as the sum of proper divisors of n
#(numbers less than n which divide evenly into n).
#If d(a) = b and d(b) = a, where a  b, then a and b are
#an amicable pair and each of a and b are called amicable numbers.
#For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11,
#20, 22, 44, 55 and 110; therefore d(220) = 284.
#The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
#Evaluate the sum of all the amicable numbers under 10000.

def d(n):
    i = 1
    summa = 0
    while i < n:
        if n % i == 0:
            summa += i
        i += 1
    return summa

n = 2
summa = 0
while n < 10000:
    m = d(n)
    h = d(m)
    if (h == n) and (m != n):
        print n, m
        summa = summa + m + n
        n = m
    n += 1
print summa
