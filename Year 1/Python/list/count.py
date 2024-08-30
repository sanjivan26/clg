n=list(map(int,input().split()))
l=[0,0,0]
for i in n:
    if i>0:
        l[0]+=1
    elif i==0:
        l[1]+=1
    else:
        l[2]+=1
for i in l:
    print("%d",i/len(n))        