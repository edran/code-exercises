#Problem 16
#2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
#What is the sum of the digits of the number 2^1000?
n = 1
for i in range(1000):
    n = 2*n
n = str(n)
k = 0
for i in range(len(n)):
    k = k + int(n[i])
print k
    


