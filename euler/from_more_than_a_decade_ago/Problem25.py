#Problem 25
#The 12th term, F12, is the first term to contain three digits.
#What is the first term in the Fibonacci sequence to contain 1000 digits?

nfib = 1
fo = 1
ft = 1
i = 2
while len(str(nfib)) != 1000:
    nfib = fo + ft
    ft = fo
    fo = nfib
    i += 1
print i, nfib
