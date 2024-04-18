import re
x=int(input())
for i in range(x):
    n=int(input())
    print(len(re.findall("pie|map",input())))