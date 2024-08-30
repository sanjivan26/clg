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

print("Given list is ",l)

possum=[0,sum(l[0])]
for i in range(len(l)):
     if sum(l[i])>possum[1]:
         possum[0]=i
         possum[1]=sum(l[i])

print("The list ",l[possum[0]]," has the highest sum")         