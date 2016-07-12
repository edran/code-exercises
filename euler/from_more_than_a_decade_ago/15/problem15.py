#Problem 15
#Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.
#How many routes are there through a 2020 grid?
#n choose k problem
def fact(n):
    best = 1
    for i in range(1, n+1):
        best = best * i

    return best

print fact(40)/(fact(20)*fact(20))
