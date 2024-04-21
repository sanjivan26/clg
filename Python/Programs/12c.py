import sys

num = sys.argv[1]
l1 = []
flag = 0
for i in range(2,int(num)):
    for j in range(2,(i//2) + 1):
        if (i%j == 0):
            flag = 1
            break
        
        else:
            flag = 0
    if(flag == 0):
        l1.append(i)

print(l1)
