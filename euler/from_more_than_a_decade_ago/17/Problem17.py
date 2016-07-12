#Problem17
#If the numbers 1 to 5 are written out in words: one, two, three, four, five,
#then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
#If all the numbers from 1 to 1000 (one thousand) inclusive were
#written out in words, how many letters would be used?

#NOTE: Do not count spaces or hyphens.
#For example, 342 (three hundred and forty-two) contains 23 letters and
#115 (one hundred and fifteen) contains 20 letters.
#The use of "and" when writing out numbers is in compliance with British usage.

import math
DEBUG = 0
def to_word(i):
    z_to_t = ['zero','one','two','three','four','five','six','seven','eight','nine','ten','eleven',
              'twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen',
              'twenty'] #zero,one,two,three...
    decades = ['zero','ten','twenty','thirty','forty','fifty','sixty','seventy','eighty','ninety'] #zero
    moar = ['zero','ten','hundred','thousand']
    k = str(i)
    zeros = math.log(i,10)
    letters = 0
    
    if i <= 20:
        letters = len(z_to_t[i])
        if DEBUG: print i, ' = ', z_to_t[i], ' = ', letters
        
    elif zeros < 2:
        if i %10 == 0:
            letters = len(decades[int(k[0])])
            if DEBUG: print i, ' = ', decades[int(k[0])], ' = ', letters
        else:
            letters = len(decades[int(k[0])]) + len(z_to_t[int(k[1])])
            if DEBUG: print i, ' = ', decades[int(k[0])], z_to_t[int(k[1])], ' = ', letters


    elif zeros < 3:
        if i == 1000:
            letters = len(z_to_t[1]) + len(moar[3])
            if DEBUG: print i, ' = ', z_to_t[1], moar[3], ' = ', letters
        elif i % 100 == 0:
            letters = len(z_to_t[int(k[0])]) + len(moar[2])
            if DEBUG: print i, ' = ', z_to_t[int(k[0])], moar[2], ' = ', letters
        elif int(k[1]) == 0:
            letters = len(z_to_t[int(k[0])]) + len(moar[2]) + len('and') + len(z_to_t[int(k[2])])
            if DEBUG: print i, ' = ', z_to_t[int(k[0])], moar[2], 'and', z_to_t[int(k[2])], ' = ', letters
        elif int(k[1]) == 1 or (int(k[1]) == 2 and int(k[2]) == 0):
            letters = len(z_to_t[int(k[0])]) + len(moar[2]) + len('and') + len(z_to_t[i-int(k[0])*100]) ##########
            if DEBUG: print i, ' = ', z_to_t[int(k[0])], moar[2], 'and', z_to_t[i-int(k[0])*100], ' = ', letters            
        elif i %10 == 0:
            letters = len(z_to_t[int(k[0])]) + len(moar[2]) + len('and') + len(decades[int(k[1])])
            if DEBUG: print i, ' = ', z_to_t[int(k[0])], moar[2], 'and',decades[int(k[1])], ' = ', letters

        else:
            letters = len(z_to_t[int(k[0])]) + len(moar[2]) + len('and') + len(decades[int(k[1])]) + len(z_to_t[int(k[2])])
            if DEBUG: print i, ' = ', z_to_t[int(k[0])], moar[2], 'and', decades[int(k[1])], z_to_t[int(k[2])], ' = ', letters
    
                      
                
        
    return letters

lett = 0

for i in range(1, 1001):
    lett = lett + to_word(i)   
print lett

