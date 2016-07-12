#Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

import math

#int(math.ceil(math.log10(number_of_input_numbers))) #how many digits more I have to calculate to get it right
#in this case, 12 digits should be fine

line = []
not_used =  []
digits = 0
f = open('numbers.txt', 'rU') #numbers.txt must stay into  the same folder as the source

# Load data
for i in range(100):
    line.append(int(f.read(12)))
    not_used.append(f.read(39))
        
f.close()
for i in range(100):
    digits = digits + line[i]
    
print line[1]
print line[2]
print line[99]
print digits


