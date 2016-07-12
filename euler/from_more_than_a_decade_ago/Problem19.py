#Problem 19
#You are given the following information,
#but you may prefer to do some research for yourself.

#1 Jan 1900 was a Monday.
#Thirty days has September,
#April, June and November.
#All the rest have thirty-one,
#Saving February alone,
#Which has twenty-eight, rain or shine.
#And on leap years, twenty-nine.
#A leap year occurs on any year evenly divisible by 4,
#but not on a century unless it is divisible by 400.
#How many Sundays fell on the first of the month during
#the twentieth century (1 Jan 1901 to 31 Dec 2000)?

import math

leap = 0 # 1 if it's a leap year
leapyear = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
normalyear = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

START = 1901
STOP = 2000
year = START
count = 0
while year <= STOP:
    
    if (year % 4) == 0:
        leap = 1
    else:
        leap = 0
        
    d = 1
    i = 0
    while d < 365:

        x = year + int(math.floor((year - 1) / 4)) - int(math.floor((year - 1) / 100)) + int(math.floor((year - 1) / 400)) + d
        if (x % 7) == 1:
            count += 1
        if leap:
            x = leapyear[i]
        else:
            x = normalyear[i]
        d = d + x
        i += 1
            
    year += 1
    print count
        
        
    


            
