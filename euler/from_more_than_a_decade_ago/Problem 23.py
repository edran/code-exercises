#Problem 23
#########################################################
#  Find the sum of all the positive integers which      #
#cannot be written as the sum of two abundant numbers.  #
#########################################################
#Upper limit =  28123

import math

DEBUG = 0
total = 0
limit = 28123 #28123
better = int(math.floor(limit))
abundants = []
sum_abundants = []
for i in range(2,better): #28123/2 + 2 is the uppest abundant we have to check
    temp_value = 0
    for k in range(1,i):
        if i % k == 0:
            temp_value = temp_value + k
    if temp_value > i:
        abundants.append(i)
print "list of abundants: done"
print "\n"

if DEBUG: print abundants, "\n"
if DEBUG == 0:
    for j in abundants:
        for m in abundants:
            jm = j + m
            if jm < limit:
                sum_abundants.append(jm)
            if DEBUG:
                if m == 12:
                    print "!"
    #print list(set(sum_abundants))
    set_sum = set(sum_abundants)
    for num in range(limit):
        if num not in set_sum:
            total += num

    print total
            

