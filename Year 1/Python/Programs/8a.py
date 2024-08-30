l=list(map(int,input().split()))
for i in range(len(l)-1,0,-1):
    for j in range(i):
        if(l[j]>l[j+1]):
            c=l[j]
            l[j]=l[j+1]
            l[j+1]=c
print(l[len(l)-int(input("Enter calue for k"))])                