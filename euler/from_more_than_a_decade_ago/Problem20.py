#n! means n * (n - 1)  ... * 3 * 2 * 1

#For example, 10! = 10  9  ...  3  2  1 = 3628800,
#and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

#Find the sum of the digits in the number 100!
def fact(n):
    num = 1
    for i in range(1, n+1):
        num = num * i
    return num
n = input("Write the number you want to factorize: ")
f = str(fact(n))
l = len(f)
s = 0
for i in range(l):
    s = s + int(f[i])

print s
    

