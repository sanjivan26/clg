x=int(input())
for i in range(x):
    n=int(input())
    l=list(map(int,input().split()))
    for i in range(n):
        if i not in l:
            sus=i
            break 


    mid=[-1,-1]
    l2=list(range(sus))
  
    
    for i in range(n):
        if l[i] in l2:
           l2.remove(l[i])
        if l2==[]:
            mid[0]=i
            break
    l2=list(range(sus))    
    for i in range(mid[0]+1,n):
        if l[i] in l2:
           l2.remove(l[i])
        if l2==[]:
            mid[1]=1
            break
    if(mid[1]==-1):
        print(-1)
    else:
        print(2)
        print(1,mid[0]+1)
        print(mid[0]+2,n)
 