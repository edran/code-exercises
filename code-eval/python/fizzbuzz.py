"""Your program should read an input file (provided on the command
line) which contains multiple newline separated lines. Each line
will contain 3 numbers which are space delimited. The first number
is first number to divide by ('A' in this example), the second
number is the second number to divide by ('B' in this example) and
the third number is where you should count till ('N' in this
example). You may assume that the input file is formatted correctly
and is the numbers are valid positive integers. E.g.

3 5 10 
2 7 15 

OUTPUT SAMPLE:

Print out the series 1 through N replacing numbers divisible by 'A'
by F, numbers divisible by 'B' by B and numbers divisible by both as
'FB'. Since the input file contains multiple sets of values, your
output will print out one line per set. Ensure that there are no
trailing empty spaces on each line you print. E.g.


1 2 F 4 B F 7 8 F B 
1 F 3 F 5 F B F 9 F 11 F 13 FB 15

Constraints: 
The number of test cases <= 20 
"A" is in range [1, 20]
"B" is in range [1, 20] 
"N" is in range [21, 100]

"""

import sys

def read_input():
    
    l = []
    f = open(sys.argv[1], "r")
    for line in f:
        a = line.split() # strips also "\n"
        l.append(a)
    
    f.close()
    return l

def fizz_buzz(A, B, N):
    """
    A -> F
    B -> B
    N is range (included)
    """
    
    f = int(A)
    b = int(B)
    n = int(N)
    
    l = []

    for i in range(1, n+1):
        if i % f == 0 and i % b == 0:
            l.append("FB")
        elif i % f == 0:
            l.append("F")
        elif i % b == 0:
            l.append("B")
        else:
            l.append(str(i)) # just to make things consistent...
    
    return l

def pretty_string(l):
    s = ""
    for i in l:
        s += i + " "
    return s[:-1]

def main():

    inp = read_input()
    # Should be testing for set of 3 in each line...
    
    for i in inp:
        A, B, N = i[0], i[1], i[2]
        d = fizz_buzz(A, B, N)
        s = pretty_string(d)
        print s



if __name__ == "__main__":
    main()
