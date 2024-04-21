def temp(x,l):
    if x == 0:
        return
    temp(x//10,l)
    l.append(x%10)

l=[]
for i in list(map(int,input().split(","))):
    l12=[]
    temp(i,l12)
    l.append(l12)

print(l)
flag=0
for i in l:
    if type(i)==type([]):
        flag=1
        break

if flag==0:
    print("Input is not a nested list")
else:
    print("Input is a nested list")    
