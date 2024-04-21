def temp(x,l):
    if x == 0:
        return
    temp(x//10,l)
    l.append(x%10)

l1=[]
for i in list(map(int,input().split(","))):
    l12=[]
    temp(i,l12)
    l1.append(l12)

l2=[]
for i in list(map(int,input().split(","))):
    l12=[]
    temp(i,l12)
    l2.append(l12)

print(l1,l2)

l3=[]
for i in range(len(l1)):
    temp=[]
    for j in range(len(l1[0])):
        temp.append(l1[i][j]+l2[i][j])
    l3.append(temp)    
print("Th3 sum is ",l3)

l4=[]
for i in range(len(l1)):
    temp=[]    
    for j in range(len(l2[0])):  
        x=0
        for k in range(len(l1[0])):
            x+=(l1[i][k]*l2[k][j])
        temp.append(x)
    l4.append(temp)        
print("The product is ",l4)            