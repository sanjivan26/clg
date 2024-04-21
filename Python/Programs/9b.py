def temp(x,l):
    temp(x//10,l)
    l.append(x%10)

l=[]
l2=[]
for i in input().split(","):
    l.append(i.split())
    if len(l2)==0:
        l2.append(i.split())
    elif len(l2)==1:
        if int(l[-1][1])>int(l2[0][1]): 
            l2.append(l2[0])
            l2[0]=i.split()      
        else:
            l2.append(i.split())
    elif int(l[-1][1])>int(l2[0][1]):   
        l2[1]=l2[0]
        l2[0]=i.split()
    elif int(l[-1][1])>int(l2[1][1]):   
        l2[1]=i.split()   

print(l)
print("The second highest mark is %s scored by %s" %(l2[1][1],l2[1][0]))        