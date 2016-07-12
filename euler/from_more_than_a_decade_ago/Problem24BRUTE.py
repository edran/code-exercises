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

DEBUG = 0

limit = 987654321
upper = 9876543210
i = 123456788
count = 0
test = 0
test_total = 0
while count != 1000:
    i += 1
    test += 1
    flag = 1
    if i <= limit:
        #if DEBUG: print "DOWN"
        #do something
        j = map(int, list(str(i)))

        for k in range(1,10):
            if k not in j:
                flag = 0
                break
    else:
        #do something else
        #if DEBUG: print "UP"
        j = list(i)

        for k in range(10):
            if k not in j:
                flag = 0
                break
    if flag:
        count += 1
        if DEBUG:
            print "###"
            print i
            print count
            print "###"
    if test == 1000000:
        test_total += test
        test = 0
        print test_total, " - working..."
            
print i
            
