#Problem 24
#A permutation is an ordered arrangement of objects.
#For example, 3124 is one possible permutation of the
#digits 1, 2, 3 and 4. If all of the permutations are
#listed numerically or alphabetically, we call it
#lexicographic order. The lexicographic permutations
#of 0, 1 and 2 are:

#012   021   102   120   201   210

#What is the millionth lexicographic permutation
#of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

import math
def fact(n):
    fact = 1
    for i in range(1,n+1):
        fact *= i
    return fact
        
DEBUG = 0

limit = 999999

i = 123456788
count = 0
test = 0
test_total = 0
mthperm = [0,0,0,0,0,0,0,0,0,0]
digits = [0,1,2,3,4,5,6,7,8,9]
temp_perm = 1
i = 0
for n in range(9,0,-1):
    print "Permutations = ",limit
    temp_perm = fact(n) #9! 8! 7! ...
    temp_digit = limit / temp_perm #1000000 / 9! / 8! / 7!
    print "FACT ",n," = ", temp_perm
    print "Index to choose: ", temp_digit, " from ", digits
    mthperm[i] = digits[int(math.floor(temp_digit))]
    digits.remove(mthperm[i])
    print mthperm
    print digits
    limit = limit - int(math.floor(temp_digit))*temp_perm
    temp_perm = 1
    i += 1
    print "####################"
print mthperm
            
