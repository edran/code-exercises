#Problem 18
#By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
#
#   3
#  7 4
# 2 4 6
#8 5 9 3
#
#That is, 3 + 7 + 4 + 9 = 23.
#
#Find the maximum total from top to bottom of the triangle below:
#
#               75
#              95 64
#             17 47 82
#            18 35 87 10
#           20 04 82 47 65
#          19 01 23 75 03 34
#         88 02 77 73 07 63 67
#        99 65 04 28 06 16 70 92
#       41 41 26 56 83 40 80 70 33
#      41 48 72 33 47 32 37 16 94 29
#     53 71 44 65 25 43 91 52 97 51 14
#    70 11 33 28 77 73 17 78 39 68 17 57
#   91 71 52 38 17 14 91 43 58 50 27 29 48
#  63 66 04 68 89 53 67 30 73 16 69 87 40 31
# 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
#########################################################################
#########################################################################
#########################################################################
#15 lines = 120 numbers


triangle = []

summa = 0
f = open('triangle.txt', 'rU')

#k = 1
#for i in range(15): #0-14
#    triangle.append([])
#    for n in range(k):
#        triangle[i].append(int(f.readline(3)))
#    k += 1

for i in range(15):
    triangle.append(f.readline())
    triangle[i] = map(int, triangle[i].split()) #PYTHON POWA! <3
for i in range(15):
    print triangle[i]
for i in range(14, 0, -1):
    for m in range(i):
        triangle[i-1][m] = triangle[i-1][m] + max(triangle[i][m], triangle[i][m+1])
print triangle[0][0]    




    
