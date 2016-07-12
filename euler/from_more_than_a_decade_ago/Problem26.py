#Problem 26
#A unit fraction contains 1 in the numerator.
#The decimal representation of the unit fractions with
#denominators 2 to 10 are given:

#1/2	= 	0.5
#1/3	= 	0.(3)
#1/4	= 	0.25
#1/5	= 	0.2
#1/6	= 	0.1(6)
#1/7	= 	0.(142857)
#1/8	= 	0.125
#1/9	= 	0.(1)
#1/10	= 	0.1
#Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
#It can be seen that 1/7 has a 6-digit recurring cycle.
#
#Find the value of d < 1000 for which 1/d contains the longest
#recurring cycle in its decimal fraction part.
import decimal
MAX = 26
numb = []

one_digit = 0
for d in range(1,1000):
    f = decimal.Decimal(1)/decimal.Decimal(d)
    f -= int(f)
    #print fraction
    fraction = list(str(f))
    map(int, f)
    length = len(f)
    i = 0
    k = 0
    is_equal = 0
    if length > 2:
        
        f.pop(0)
        f.pop(0)
        
        if fraction[i] == f[1+1] == f[i+2] == f[1+3] == f[1+4] == f[1+5]:
            one_digit = 1
            
        numb.append(f[i])
        k += 1
        
        
    print d

    
    
