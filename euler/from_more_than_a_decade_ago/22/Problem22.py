#Problem 22
#
#Using names.txt (right click and 'Save Link/Target As...'),
#a 46K text file containing over five-thousand first names,
#begin by sorting it into alphabetical order. Then working out
#the alphabetical value for each name, multiply this value by
#its alphabetical position in the list to obtain a name score.

#For example, when the list is sorted into alphabetical order,
#COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th
#name in the list. So, COLIN would obtain a score of 938 * 53 = 49714.

#What is the total of all the name scores in the file?

alph = ["0","a","b","c","d","e","f","g","h","i","j",
        "k","l","m","n","o","p","q","r","s","t","u",
        "v","w","x","y","z"]

f = open('names.txt', 'r')
file_contents = f.read()
f.close()

def score(n):
    score = 0
    n = n.lower()
    for char in n:
        score = score + alph.index(char)
    return score

value = 0
summa = 0

list_names = file_contents.split(',')
list_names.sort()
lenlist = len(list_names)
for name in list_names:
    sname = name.strip('"')
    value = score(sname) * (list_names.index(name)+1)
    summa += value
    print summa





